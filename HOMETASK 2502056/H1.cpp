
#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    Patient* next;
};
class Hospital {
private:
    Patient* head;

public:
    Hospital() {
        head = nullptr;
    }
    void addPatient(int id, string name, int age) {
        Patient* newPatient = new Patient{id, name, age, nullptr};

        if (head == nullptr) {
            head = newPatient;
        } else {
            Patient* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newPatient;
        }

        cout << "Patient added successfully at the end.\n";
    }
    void addEmergencyPatient(int id, string name, int age) {
        Patient* newPatient = new Patient{id, name, age, head};
        head = newPatient;

        cout << "Emergency patient added at the beginning.\n";
    }
    void searchPatient(int id) {
        Patient* temp = head;

        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "\nPatient found!\n";
                cout << "Patient ID: " << temp->id << endl;
                cout << "Patient Name: " << temp->name << endl;
                cout << "Patient Age: " << temp->age << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Patient with ID " << id << " does not exist.\n";
    }
    void removePatient(int id) {
        if (head == nullptr) {
            cout << "No patients are waiting.\n";
            return;
        }
        if (head->id == id) {
            Patient* temp = head;
            head = head->next;
            delete temp;

            cout << "Patient treated and removed successfully.\n";
            return;
        }

        Patient* temp = head;

        while (temp->next != nullptr && temp->next->id != id) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Patient with ID " << id << " does not exist.\n";
            return;
        }
        Patient* patientToDelete = temp->next;
        temp->next = patientToDelete->next;
        delete patientToDelete;

        cout << "Patient treated and removed successfully.\n";
    }
    void displayPatients() {
        if (head == nullptr) {
            cout << "No patients are currently waiting.\n";
            return;
        }

        Patient* temp = head;

        cout << "\n===== Waiting Patients =====\n";

        while (temp != nullptr) {
            cout << "Patient ID: " << temp->id << endl;
            cout << "Patient Name: " << temp->name << endl;
            cout << "Patient Age: " << temp->age << endl;
            cout << "----------------------------\n";

            temp = temp->next;
        }
    }
    ~Hospital() {
        Patient* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    Hospital hospital;
    int choice, id, age;
    string name;

    do {
        cout << "\n===== Hospital Patient Management =====\n";
        cout << "1. Add a new patient at the end\n";
        cout << "2. Add an emergency patient at the beginning\n";
        cout << "3. Search for a patient by ID\n";
        cout << "4. Remove a patient after treatment\n";
        cout << "5. Display all waiting patients\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;

                cout << "Enter Patient Name: ";
                getline(cin >> ws, name);

                cout << "Enter Patient Age: ";
                cin >> age;

                hospital.addPatient(id, name, age);
                break;

            case 2:
                cout << "Enter Emergency Patient ID: ";
                cin >> id;

                cout << "Enter Patient Name: ";
                getline(cin >> ws, name);

                cout << "Enter Patient Age: ";
                cin >> age;

                hospital.addEmergencyPatient(id, name, age);
                break;

            case 3:
                cout << "Enter Patient ID to search: ";
                cin >> id;

                hospital.searchPatient(id);
                break;

            case 4:
                cout << "Enter Patient ID to remove: ";
                cin >> id;

                hospital.removePatient(id);
                break;

            case 5:
                hospital.displayPatients();
                break;

            case 6:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
