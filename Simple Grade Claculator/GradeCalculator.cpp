#include <iostream>
using namespace std;

int main()
{
    int marks;
    char grade;
    cout << "Enter your marks: ";
    cin >> marks;

    grade = (marks > 100) ? 'n' : (marks >= 90) ? 'A'
                              : (marks >= 80)   ? 'B'
                              : (marks >= 70)   ? 'C'
                              : (marks >= 60)   ? 'D'
                                                : 'F';

    cout << "your grade is: " << grade << endl;
    switch (grade)
    {
    case 'A':
        cout << "Excellent Work!" << endl;
        break;
    case 'B':
        cout << "Wall done" << endl;
        break;
    case 'C':
        cout << "Good job" << endl;
        break;
    case 'D':
        cout << "You Pass,but you could do battr" << endl;
        break;
    case 'F':
        cout << "Soory, you failed" << endl;
        break;
    default:
        cout << "Invalid input" << endl;
    }
    if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D')
    {
        cout << "Congratulations! You are eligible for next lave.";
    }
    else if(grade =='F')
    {
        cout << "Please try again next time.";
    }
    else{
        cout<<" ";
    }
}
