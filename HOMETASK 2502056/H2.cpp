#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    bool present;
    Student* next;
};

class AttendanceList {
private:
    Student* head;

public:
    
    AttendanceList() {
        head = nullptr;
    }
    void addStudent(int rollNumber, string name, bool present) {
        Student* newStudent = new Student;
        
        newStudent->rollNumber = rollNumber;
        newStudent->name = name;
        newStudent->present = present;
        newStudent->next = nullptr;
        if (head == nullptr) {
            head = newStudent;
        }
        else {
            Student* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newStudent;
        }

        cout << "Student added successfully.\n";
    }

    
    void searchStudent(int rollNumber) {
        Student* temp = head;

        while (temp != nullptr) {
            if (temp->rollNumber == rollNumber) {
                cout << "\nStudent found!\n";
                cout << "Roll Number: " << temp->rollNumber << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Attendance: ";

                if (temp->present)
                    cout << "Present\n";
                else
                    cout << "Absent\n";

                return;
            }

            temp = temp->next;
        }

        cout << "Student not found.\n";
    }

 
    void deleteStudent(int rollNumber) {

    
        if (head == nullptr) {
            cout << "Student not found.\n";
            return;
        }

        if (head->rollNumber == rollNumber) {
            Student* temp = head;
            head = head->next;

            delete temp;

            cout << "Student deleted successfully.\n";
            return;
        }

        Student* temp = head;

        while (temp->next != nullptr &&
               temp->next->rollNumber != rollNumber) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student not found.\n";
            return;
        }

        Student* studentToDelete = temp->next;

        temp->next = studentToDelete->next;

        delete studentToDelete;

        cout << "Student deleted successfully.\n";
    }
 
    void displayStudents() {

        if (head == nullptr) {
            cout << "Attendance list is empty.\n";
            return;
        }

        Student* temp = head;

        cout << "\n===== Attendance List =====\n";

        while (temp != nullptr) {

            cout << "Roll Number: " << temp->rollNumber << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Attendance: ";

            if (temp->present)
                cout << "Present\n";
            else
                cout << "Absent\n";

            cout << "--------------------------\n";

            temp = temp->next;
        }
    }

    // 5. Count total students present
    int countPresent() {

        int count = 0;
        Student* temp = head;

        while (temp != nullptr) {

            if (temp->present == true) {
                count++;
            }

            temp = temp->next;
        }

        return count;
    }


    void displayFinalAttendance() {

        cout << "\n===== FINAL ATTENDANCE LIST =====\n";

        if (head == nullptr) {
            cout << "No students in the attendance list.\n";
            return;
        }

        Student* temp = head;

        while (temp != nullptr) {

            cout << "Roll Number: " << temp->rollNumber
                 << " | Name: " << temp->name
                 << " | Status: ";

            if (temp->present)
                cout << "Present";
            else
                cout << "Absent";

            cout << endl;

            temp = temp->next;
        }

        cout << "\nTotal Students Present: "
             << countPresent() << endl;
    }


    ~AttendanceList() {

        Student* temp;

        while (head != nullptr) {

            temp = head;
            head = head->next;

            delete temp;
        }
    }
};


// Main function
int main() {

    AttendanceList attendance;

    int choice;
    int rollNumber;
    string name;
    char status;

    do {

        cout << "\n====================================\n";
        cout << " UNIVERSITY ATTENDANCE SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Count Present Students\n";
        cout << "6. Display Final Attendance List\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            // Add student
            case 1:

                cout << "Enter Roll Number: ";
                cin >> rollNumber;

                cout << "Enter Student Name: ";
                getline(cin >> ws, name);

                cout << "Enter Attendance Status (P/A): ";
                cin >> status;

                if (status == 'P' || status == 'p') {
                    attendance.addStudent(rollNumber, name, true);
                }
                else if (status == 'A' || status == 'a') {
                    attendance.addStudent(rollNumber, name, false);
                }
                else {
                    cout << "Invalid attendance status.\n";
                }

                break;


            // Search student
            case 2:

                cout << "Enter Roll Number to search: ";
                cin >> rollNumber;

                attendance.searchStudent(rollNumber);

                break;


            // Delete student
            case 3:

                cout << "Enter Roll Number to delete: ";
                cin >> rollNumber;

                attendance.deleteStudent(rollNumber);

                break;


            // Display all students
            case 4:

                attendance.displayStudents();

                break;


            // Count present students
            case 5:

                cout << "\nTotal Students Present: "
                     << attendance.countPresent()
                     << endl;

                break;


            // Final attendance
            case 6:

                attendance.displayFinalAttendance();

                break;


            // Exit
            case 7:

                cout << "Exiting program...\n";

                break;


            default:

                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);


    return 0;
}
