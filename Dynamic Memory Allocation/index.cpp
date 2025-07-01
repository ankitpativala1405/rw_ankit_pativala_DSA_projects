#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert_Start(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void delete_node(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insert_Start(10);
    list.insert_Start(20);
    list.insert_Start(30);

    cout << "Linked List: ";
    list.display();

    int key = 20;
    if (list.search(key))
        cout << "Key " << key << " found in the list." << endl;
    else
        cout << "Key " << key << " not found in the list." << endl;

    list.delete_node(20);
    cout << "Linked List after deleting 20: ";
    list.display();

    list.reverse();
    cout << "Linked List after reversing: ";
    list.display();

    return 0;
}
