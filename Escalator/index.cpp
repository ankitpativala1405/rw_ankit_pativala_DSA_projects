#include <iostream>
using namespace std;


class StackBase {
public:
    void message() {
        cout << "This is a StackBase class.\n";
    }
};


class Stack : public StackBase {
private:
    int arr[5];
    int topIndex;

public:

    Stack() {
        topIndex = -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full.\n";
        } else {
            arr[++topIndex] = value;
            cout << "Pushed: " << value << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Popped: " << arr[topIndex--] << endl;
        }
    }

    void top() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top element: " << arr[topIndex] << endl;
        }
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 4; 
    }
};


int main() {
    Stack s; 
    s.message(); 

    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display Top\n4. Check Empty\n5. Check Full\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.top();
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
            break;
        case 5:
            cout << (s.isFull() ? "Stack is full.\n" : "Stack is not full.\n");
            break;
        case 6:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
