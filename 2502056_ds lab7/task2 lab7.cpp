
#include <iostream>
using namespace std;

int main() {
    int q[5], front = 0, rear = -1, count = 0;
    int choice, packet;

    do {
        cout << "\n1. Insert Packet\n2. Transmit Packet\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count == 5) {
                cout << "Queue Overflow!\n";
            } else {
                cout << "Enter packet ID: ";
                cin >> packet;

                rear = (rear + 1) % 5;
                q[rear] = packet;
                count++;

                cout << "Packet added.\n";
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "Queue Underflow!\n";
            } else {
                cout << "Transmitting packet: "
                     << q[front] << endl;

                front = (front + 1) % 5;
                count--;
            }
        }
        else if (choice == 3) {
            if (count == 0) {
                cout << "Queue is empty.\n";
            } else {
                for (int i = 0; i < count; i++)
                    cout << q[(front + i) % 5] << " ";
                cout << endl;
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

