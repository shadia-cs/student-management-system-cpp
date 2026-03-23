#include <iostream>
#include <vector>
using namespace std;

// Enum with explicit values
enum MenuChoice { ADD = 1, VIEW = 2, DELETE = 3,  EXIT = 4 };

// Student structure
struct Student {
    string name;
    int id;
    float gpa;
};

// Function to read student data
void readStudentInfo(Student& info) {
    cout << "Enter student Name: ";
    cin.ignore();
    getline(cin, info.name);

    cout << "Enter student ID: ";
    cin >> info.id;

    cout << "Enter student GPA: ";
    cin >> info.gpa;
}

// Function to print student data
void printStudentInfo(Student info) {
    cout << "Name: " << info.name << endl;
    cout << "ID: " << info.id << endl;
    cout << "GPA: " << info.gpa << endl;
}

int main() {

    vector<Student> students;
    int choice;

    while (true) {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        // Add Student
        if (choice == ADD) {
            Student s;
            readStudentInfo(s);
            students.push_back(s);
            cout << "Student added successfully!\n";
        }

        // View Students
        else if (choice == VIEW) {
            if (students.size() == 0) {
                cout << "No students found.\n";
            }
            else {
                for (int i = 0; i < students.size(); i++) {
                    if (students[i].id != -1) {
                        cout << "\nStudent " << i + 1 << endl;
                        printStudentInfo(students[i]);
                    }
                }
            }
        }

        // Delete Student
        else if (choice == DELETE) {
            int id;
            cout << "Enter student ID to delete: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == id) {
                    students[i].id = -1; // mark as deleted
                    cout << "Student deleted.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        // Exit
        else if (choice == EXIT) {
            cout << "\nTHE END\n";
            break;
        }

        // Invalid input
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}