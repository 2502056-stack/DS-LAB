#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    string patientID;
    Patient* next;

public:
    Patient(string id)
    {
        patientID = id;
        next = NULL;
    }

    string getPatientID()
    {
        return patientID;
    }

    Patient* getNext()
    {
        return next;
    }

    void setNext(Patient* node)
    {
        next = node;
    }
};

class PatientQueue
{
private:
    Patient* front;
    Patient* rear;

public:
    PatientQueue()
    {
        front = NULL;
        rear = NULL;
    }

    void addPatient(string patientID)
    {
        Patient* newPatient = new Patient(patientID);

        if (front == NULL)
        {
            front = rear = newPatient;
            return;
        }

        rear->setNext(newPatient);
        rear = newPatient;
    }

    void displayPatients()
    {
        if (front == NULL)
        {
            cout << "No patients waiting." << endl;
            return;
        }

        Patient* temp = front;

        cout << "Waiting Patients: ";

        while (temp != NULL)
        {
            cout << temp->getPatientID();

            if (temp->getNext() != NULL)
            {
                cout << " -> ";
            }

            temp = temp->getNext();
        }

        cout << endl;
    }

    void servePatient()
    {
        if (front == NULL)
        {
            cout << "No patients waiting." << endl;
            return;
        }

        Patient* temp = front;

        cout << "Patient "
             << temp->getPatientID()
             << " is being served." << endl;

        front = front->getNext();

        delete temp;

        if (front == NULL)
        {
            rear = NULL;
        }
    }
};

int main()
{
    PatientQueue queue;

    queue.addPatient("P101");
    queue.addPatient("P102");
    queue.addPatient("P103");
    queue.addPatient("P104");

    queue.displayPatients();

    queue.servePatient();

    cout << "Updated Queue:" << endl;
    queue.displayPatients();

    return 0;
}

