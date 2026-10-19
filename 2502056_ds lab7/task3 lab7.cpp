
#include <iostream>
using namespace std;

int main() {
    int id[5], priority[5];
    int count = 0, choice, pID, p;

    do {
        cout << "\n1. Add Patient\n2. Treat Patient\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count == 5) {
                cout << "Priority Queue is full!\n";
            } else {
                cout << "Enter patient ID: ";
                cin >> pID;
                cout << "Enter priority (1 = highest): ";
                cin >> p;

                if (p < 1) {
                    cout << "Invalid priority!\n";
                } else {
                    int i = count - 1;

                    while (i >= 0 && priority[i] > p) {
                        id[i + 1] = id[i];
                        priority[i + 1] = priority[i];
                        i--;
                    }

                    id[i + 1] = pID;
                    priority[i + 1] = p;
                    count++;

                    cout << "Patient added.\n";
                }
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "No patients waiting!\n";
            } else {
                cout << "Treating patient P" << id[0]
                     << ", Priority: " << priority[0] << endl;

                for (int i = 0; i < count - 1; i++) {
                    id[i] = id[i + 1];
                    priority[i] = priority[i + 1];
                }

                count--;
            }
        }
        else if (choice == 3) {
            if (count == 0) {
                cout << "No patients waiting.\n";
            } else {
                for (int i = 0; i < count; i++)
                    cout << "Patient P" << id[i]
                         << " Priority: " << priority[i] << endl;
            }
        }
        else if (choice == 4) {
            cout << "Program ended.\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

