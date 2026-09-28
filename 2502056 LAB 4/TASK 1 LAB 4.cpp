#include <iostream>
using namespace std;

class Student
{
private:
    int rollNumber;
    Student* next;

public:
    Student(int roll)
    {
        rollNumber = roll;
        next = NULL;
    }

    int getRollNumber()
    {
        return rollNumber;
    }

    Student* getNext()
    {
        return next;
    }

    void setNext(Student* node)
    {
        next = node;
    }
};

class StudentList
{
private:
    Student* head;

public:
    StudentList()
    {
        head = NULL;
    }

    void addStudent(int rollNumber)
    {
        Student* newStudent = new Student(rollNumber);

        if (head == NULL)
        {
            head = newStudent;
            return;
        }

        Student* temp = head;

        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }

        temp->setNext(newStudent);
    }

    void displayStudents()
    {
        if (head == NULL)
        {
            cout << "No students registered." << endl;
            return;
        }

        Student* temp = head;

        cout << "Registered Students: ";

        while (temp != NULL)
        {
            cout << temp->getRollNumber();

            if (temp->getNext() != NULL)
            {
                cout << " -> ";
            }

            temp = temp->getNext();
        }

        cout << endl;
    }

    void searchStudent(int rollNumber)
    {
        Student* temp = head;

        while (temp != NULL)
        {
            if (temp->getRollNumber() == rollNumber)
            {
                cout << "Student Found" << endl;
                return;
            }

            temp = temp->getNext();
        }

        cout << "Student Not Found" << endl;
    }
};

int main()
{
    StudentList list;

    list.addStudent(101);
    list.addStudent(105);
    list.addStudent(108);
    list.addStudent(112);

    list.displayStudents();

    int rollNumber;

    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    list.searchStudent(rollNumber);

    return 0;
}
