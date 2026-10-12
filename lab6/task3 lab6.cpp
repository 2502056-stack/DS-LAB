#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Handled Patient Request: "
             << temp->patientID << endl;

        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "No patient requests." << endl;
            return;
        }

        Node* temp = top;
        cout << "Patient Requests (TOP to Bottom):" << endl;

        while (temp != NULL) {
            cout << temp->patientID << endl;
            temp = temp->next;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Current TOP Request: "
                 << top->patientID << endl;
        }
    }

    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack hospital;

    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    cout << "Before POP:" << endl;
    hospital.display();

    cout << "\nPerforming POP:" << endl;
    hospital.pop();

    cout << "\nAfter POP:" << endl;
    hospital.displayTop();

    cout << "\nRemaining Patient Requests:" << endl;
    hospital.display();

    return 0;
}
