
#include <iostream>
using namespace std;

int main() {
    int q[5], front = 0, rear = -1, count = 0;
    int choice, id;

    do {
        cout << "\n1. Insert Front\n2. Insert Rear\n";
        cout << "3. Delete Front\n4. Delete Rear\n";
        cout << "5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count == 5) {
                cout << "Deque is full!\n";
            } else {
                cout << "Enter request ID: ";
                cin >> id;

                if (count == 0)
                    front = rear = 0;
                else
                    front = (front - 1 + 5) % 5;

                q[front] = id;
                count++;
                cout << "Inserted at front.\n";
            }
        }
        else if (choice == 2) {
            if (count == 5) {
                cout << "Deque is full!\n";
            } else {
                cout << "Enter request ID: ";
                cin >> id;

                if (count == 0)
                    front = rear = 0;
                else
                    rear = (rear + 1) % 5;

                q[rear] = id;
                count++;
                cout << "Inserted at rear.\n";
            }
        }
        else if (choice == 3) {
            if (count == 0) {
                cout << "Deque is empty!\n";
            } else {
                cout << "Removed from front: " << q[front] << endl;

                front = (front + 1) % 5;
                count--;

                if (count == 0) {
                    front = 0;
                    rear = -1;
                }
            }
        }
        else if (choice == 4) {
            if (count == 0) {
                cout << "Deque is empty!\n";
            } else {
                cout << "Removed from rear: " << q[rear] << endl;

                rear = (rear - 1 + 5) % 5;
                count--;

                if (count == 0) {
                    front = 0;
                    rear = -1;
                }
            }
        }
        else if (choice == 5) {
            if (count == 0) {
                cout << "Deque is empty.\n";
            } else {
                for (int i = 0; i < count; i++)
                    cout << q[(front + i) % 5] << " ";
                cout << endl;
            }
        }
        else if (choice == 6) {
            cout << "Program ended.\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}

