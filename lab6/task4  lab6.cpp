#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string orderID;
    Node* next;

    Node(string id) {
        orderID = id;
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
        cout << "Processed Order: " << temp->orderID << endl;

        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "No orders remaining." << endl;
            return;
        }

        Node* temp = top;
        cout << "Orders (TOP to Bottom):" << endl;

        while (temp != NULL) {
            cout << temp->orderID << endl;
            temp = temp->next;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Current TOP Order: " << top->orderID << endl;
        }
    }

    bool isEmpty() {
        return top == NULL;
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
    Stack restaurant;

    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");

    cout << "Before POP:" << endl;
    restaurant.display();

    cout << "\nPerforming Two POP Operations:" << endl;
    restaurant.pop();
    restaurant.pop();

    cout << "\nAfter POP:" << endl;
    restaurant.displayTop();

    cout << "\nRemaining Orders:" << endl;
    restaurant.display();

    cout << "\nChecking Stack:" << endl;

    if (restaurant.isEmpty()) {
        cout << "Stack is Empty." << endl;
    } else {
        cout << "Stack is Not Empty." << endl;
    }

    return 0;
}
