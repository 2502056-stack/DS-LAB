#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string actions[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is Full!" << endl;
        } else {
            top++;
            actions[top] = action;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Undo action: " << actions[top] << endl;
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "No actions remaining." << endl;
            return;
        }

        cout << "Actions (TOP to Bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "No current action." << endl;
        } else {
            cout << "Current TOP action: "
                 << actions[top] << endl;
        }
    }
};

int main() {
    Stack editor;

    editor.push("Type Hello");
    editor.push("Type World");
    editor.push("Add !");
    editor.push("Delete !");

    cout << "Before Undo:" << endl;
    editor.display();

    cout << "\nPerforming Two Undo Operations:" << endl;
    editor.pop();
    editor.pop();

    cout << "\nAfter Undo:" << endl;
    editor.displayTop();

    cout << "\nRemaining Actions:" << endl;
    editor.display();

    return 0;
}
