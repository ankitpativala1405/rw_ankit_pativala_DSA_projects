#include <iostream>
#include <vector>
using namespace std;

class memoryCalculate
{
private:
    int id;
    string name;

public:
    memoryCalculate(int id, string name)
    {
        this->id = id;
        this->name = name;
    }

    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    int getId() const
    {
        return id;
    }
};

int main()
{
    vector<memoryCalculate> students;
    int choice;

    do
    {
        cout << "||student management system||" << endl;
        cout << "1.Add a student" << endl;
        cout << "2.Display all students" << endl;
        cout << "3.Remove student by ID" << endl;
        cout << "4.Search student by ID" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name;
            cout << "Enter your id: ";
            cin >> id;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            students.push_back(memoryCalculate(id, name));
            cout << "Student added successfully."<<endl;
            break;
        }

        case 2:
        {
            if (students.empty())
            {
                cout << "no student" <<endl;
            }
            else
            {
                cout << "list of student"<<endl;
                for (const auto &student : students)
                {
                    student.display();
                }
            }
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter student id to remove: ";
            cin >> id;
            bool found = false;
            for (auto it = students.begin(); it != students.end(); ++it)
            {
                if (it->getId() == id)
                {
                    students.erase(it);
                    cout << "Student removed successfully."<<endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Student with ID " << id << " not found."<<endl;
            }
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter Student ID to search: ";
            cin >> id;
            bool found = false;
            for (const auto &student : students)
            {
                if (student.getId() == id)
                {
                    cout << "Student found: "<<endl;
                    student.display();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Student with ID " << id << " not found."<<endl;
            }
            break;
        }

        case 5:
        {
            cout << "Exiting the program."<<endl;
            break;
        }

        default:
        {
            cout << "Invalid choice. Please try again."<<endl;
        }
        }

    } while (choice = 5);

    return 0;
}
