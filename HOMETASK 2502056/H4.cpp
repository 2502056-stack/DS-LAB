#include <iostream>
#include <string>
using namespace std;

// Node structure for each course
struct Course {
    string courseCode;
    string courseName;
    int creditHours;
    Course* next;
};

// Singly Linked List class
class CourseList {
private:
    Course* head;

public:

    // Constructor
    CourseList() {
        head = nullptr;
    }

    // 1. Add Course at Beginning
    void addAtBeginning(string code, string name, int credits) {

        Course* newCourse = new Course;

        newCourse->courseCode = code;
        newCourse->courseName = name;
        newCourse->creditHours = credits;

        // New course points to current first course
        newCourse->next = head;

        // New course becomes the first course
        head = newCourse;

        cout << "Course added at the beginning successfully.\n";
    }

    // 2. Add Course at End
    void addAtEnd(string code, string name, int credits) {

        Course* newCourse = new Course;

        newCourse->courseCode = code;
        newCourse->courseName = name;
        newCourse->creditHours = credits;
        newCourse->next = nullptr;

        // If list is empty
        if (head == nullptr) {
            head = newCourse;
        }
        else {

            Course* temp = head;

            // Move to the last node
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            // Add new course at the end
            temp->next = newCourse;
        }

        cout << "Course added at the end successfully.\n";
    }

    // 3. Search Course by Course Code
    void searchCourse(string code) {

        Course* temp = head;

        while (temp != nullptr) {

            if (temp->courseCode == code) {

                cout << "\nCourse Found!\n";
                cout << "Course Code: " << temp->courseCode << endl;
                cout << "Course Name: " << temp->courseName << endl;
                cout << "Credit Hours: " << temp->creditHours << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "Course not found.\n";
    }

    // 4. Delete Course by Course Code
    void deleteCourse(string code) {

        // If list is empty
        if (head == nullptr) {
            cout << "Course not found.\n";
            return;
        }

        // If the course is the first node
        if (head->courseCode == code) {

            Course* temp = head;

            head = head->next;

            delete temp;

            cout << "Course deleted successfully.\n";

            return;
        }

        Course* temp = head;

        // Find the course
        while (temp->next != nullptr &&
               temp->next->courseCode != code) {

            temp = temp->next;
        }

        // Course not found
        if (temp->next == nullptr) {

            cout << "Course not found.\n";

            return;
        }

        // Delete the course
        Course* courseToDelete = temp->next;

        temp->next = courseToDelete->next;

        delete courseToDelete;

        cout << "Course deleted successfully.\n";
    }

    // 5. Display All Courses
    void displayCourses() {

        if (head == nullptr) {

            cout << "No courses available.\n";

            return;
        }

        Course* temp = head;

        cout << "\n========== Course List ==========\n";

        while (temp != nullptr) {

            cout << "Course Code: " << temp->courseCode << endl;
            cout << "Course Name: " << temp->courseName << endl;
            cout << "Credit Hours: " << temp->creditHours << endl;
            cout << "---------------------------------\n";

            temp = temp->next;
        }
    }

    // 6. Count Total Courses
    int countCourses() {

        int count = 0;

        Course* temp = head;

        while (temp != nullptr) {

            count++;

            temp = temp->next;
        }

        return count;
    }

    // 7. Concatenate Another Course List
    void concatenate(CourseList& otherList) {

        // If the other list is empty
        if (otherList.head == nullptr) {
            return;
        }

        // If this list is empty
        if (head == nullptr) {

            head = otherList.head;

            return;
        }

        Course* temp = head;

        // Move to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Connect the last node of this list
        // to the first node of the other list
        temp->next = otherList.head;
    }

    // Display only course codes
    void displayCourseCodes() {

        if (head == nullptr) {

            cout << "Empty List";

            return;
        }

        Course* temp = head;

        while (temp != nullptr) {

            cout << temp->courseCode;

            if (temp->next != nullptr) {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    // Destructor
    ~CourseList() {

        Course* temp;

        while (head != nullptr) {

            temp = head;

            head = head->next;

            delete temp;
        }
    }
};


// Function to display menu
void displayMenu() {

    cout << "\n========================================\n";
    cout << " UNIVERSITY COURSE MANAGEMENT SYSTEM\n";
    cout << "========================================\n";

    cout << "1. Add Course at Beginning\n";
    cout << "2. Add Course at End\n";
    cout << "3. Search Course\n";
    cout << "4. Delete Course\n";
    cout << "5. Display All Courses\n";
    cout << "6. Count Total Courses\n";
    cout << "7. Concatenate Another Course List\n";
    cout << "8. Exit\n";
}


// Main function
int main() {

    CourseList morningCourses;
    CourseList eveningCourses;

    int choice;
    int listChoice;
    int creditHours;

    string courseCode;
    string courseName;

    do {

        displayMenu();

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            // 1. Add Course at Beginning
            case 1:

                cout << "\nWhich list?\n";
                cout << "1. Morning Courses\n";
                cout << "2. Evening Courses\n";
                cout << "Enter choice: ";
                cin >> listChoice;

                cout << "Enter Course Code: ";
                cin >> courseCode;

                cout << "Enter Course Name: ";
                getline(cin >> ws, courseName);

                cout << "Enter Credit Hours: ";
                cin >> creditHours;

                if (listChoice == 1) {

                    morningCourses.addAtBeginning(
                        courseCode,
                        courseName,
                        creditHours
                    );

                }
                else if (listChoice == 2) {

                    eveningCourses.addAtBeginning(
                        courseCode,
                        courseName,
                        creditHours
                    );

                }
                else {

                    cout << "Invalid list choice.\n";
                }

                break;


            // 2. Add Course at End
            case 2:

                cout << "\nWhich list?\n";
                cout << "1. Morning Courses\n";
                cout << "2. Evening Courses\n";
                cout << "Enter choice: ";
                cin >> listChoice;

                cout << "Enter Course Code: ";
                cin >> courseCode;

                cout << "Enter Course Name: ";
                getline(cin >> ws, courseName);

                cout << "Enter Credit Hours: ";
                cin >> creditHours;

                if (listChoice == 1) {

                    morningCourses.addAtEnd(
                        courseCode,
                        courseName,
                        creditHours
                    );

                }
                else if (listChoice == 2) {

                    eveningCourses.addAtEnd(
                        courseCode,
                        courseName,
                        creditHours
                    );

                }
                else {

                    cout << "Invalid list choice.\n";
                }

                break;


            // 3. Search Course
            case 3:

                cout << "\nWhich list do you want to search?\n";
                cout << "1. Morning Courses\n";
                cout << "2. Evening Courses\n";
                cout << "Enter choice: ";
                cin >> listChoice;

                cout << "Enter Course Code: ";
                cin >> courseCode;

                if (listChoice == 1) {

                    morningCourses.searchCourse(courseCode);

                }
                else if (listChoice == 2) {

                    eveningCourses.searchCourse(courseCode);

                }
                else {

                    cout << "Invalid list choice.\n";
                }

                break;


            // 4. Delete Course
            case 4:

                cout << "\nWhich list do you want to delete from?\n";
                cout << "1. Morning Courses\n";
                cout << "2. Evening Courses\n";
                cout << "Enter choice: ";
                cin >> listChoice;

                cout << "Enter Course Code to delete: ";
                cin >> courseCode;

                if (listChoice == 1) {

                    morningCourses.deleteCourse(courseCode);

                }
                else if (listChoice == 2) {

                    eveningCourses.deleteCourse(courseCode);

                }
                else {

                    cout << "Invalid list choice.\n";
                }

                break;


            // 5. Display All Courses
            case 5:

                cout << "\n===== MORNING COURSES =====\n";
                morningCourses.displayCourses();

                cout << "\n===== EVENING COURSES =====\n";
                eveningCourses.displayCourses();

                break;


            // 6. Count Total Courses
            case 6:

                cout << "\nTotal Morning Courses: "
                     << morningCourses.countCourses()
                     << endl;

                cout << "Total Evening Courses: "
                     << eveningCourses.countCourses()
                     << endl;

                cout << "Total Courses in Both Lists: "
                     << morningCourses.countCourses()
                     + eveningCourses.countCourses()
                     << endl;

                break;


            // 7. Concatenate Another Course List
            case 7:

                cout << "\nMorning Courses:\n";
                morningCourses.displayCourseCodes();

                cout << "Evening Courses:\n";
                eveningCourses.displayCourseCodes();

                // Make a copy of the morning list for demonstration
                // using the existing nodes is not safe because the
                // destructor would eventually try to delete them twice.

                cout << "\nTo create the combined list, enter the "
                     << "courses again in a combined list.\n";

                {
                    CourseList combinedCourses;

                    // Add morning courses manually according to
                    // the existing example.
                    cout << "\nEnter courses for Combined List.\n";
                    cout << "First, enter Morning Courses.\n";

                    int morningCount;

                    cout << "How many morning courses? ";
                    cin >> morningCount;

                    for (int i = 0; i < morningCount; i++) {

                        cout << "\nCourse " << i + 1 << endl;

                        cout << "Course Code: ";
                        cin >> courseCode;

                        cout << "Course Name: ";
                        getline(cin >> ws, courseName);

                        cout << "Credit Hours: ";
                        cin >> creditHours;

                        combinedCourses.addAtEnd(
                            courseCode,
                            courseName,
                            creditHours
                        );
                    }

                    cout << "\nNow enter Evening Courses.\n";

                    int eveningCount;

                    cout << "How many evening courses? ";
                    cin >> eveningCount;

                    for (int i = 0; i < eveningCount; i++) {

                        cout << "\nCourse " << i + 1 << endl;

                        cout << "Course Code: ";
                        cin >> courseCode;

                        cout << "Course Name: ";
                        getline(cin >> ws, courseName);

                        cout << "Credit Hours: ";
                        cin >> creditHours;

                        combinedCourses.addAtEnd(
                            courseCode,
                            courseName,
                            creditHours
                        );
                    }

                    cout << "\n===== COMBINED COURSE LIST =====\n";

                    combinedCourses.displayCourseCodes();

                    cout << "\nTotal Combined Courses: "
                         << combinedCourses.countCourses()
                         << endl;
                }

                break;


            // 8. Exit
            case 8:

                cout << "\nExiting program...\n";

                break;


            default:

                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 8);


    return 0;
}
