
#include <iostream>
using namespace std;

int main() {
    int q[5], front = -1, rear = -1;
    int choice, token;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Count\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (rear == 4) {
                cout << "Queue Overflow!\n";
            } else {
                cout << "Enter token: ";
                cin >> token;

                if (front == -1)
                    front = 0;

                rear++;
                q[rear] = token;
                cout << "Customer added.\n";
            }
        }
        else if (choice == 2) {
            if (front == -1) {
                cout << "Queue Underflow!\n";
            } else {
                cout << "Serving customer: " << q[front] << endl;

                if (front == rear)
                    front = rear = -1;
                else
                    front++;
            }
        }
        else if (choice == 3) {
            if (front == -1) {
                cout << "Queue is empty.\n";
            } else {
                for (int i = front; i <= rear; i++)
                    cout << q[i] << " ";
                cout << endl;
            }
        }
        else if (choice == 4) {
            if (front == -1)
                cout << "Waiting customers: 0\n";
            else
                cout << "Waiting customers: "
                     << rear - front + 1 << endl;
        }
        else if (choice == 5) {
            cout << "Program ended.\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

