#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string pages[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack is Full!" << endl;
        } else {
            top++;
            pages[top] = page;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Back button pressed. Removed: "
                 << pages[top] << endl;
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Browsing history is empty." << endl;
            return;
        }

        cout << "Browsing History (TOP to Bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "No current page." << endl;
        } else {
            cout << "Current TOP page: "
                 << pages[top] << endl;
        }
    }
};

int main() {
    Stack browser;

    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    cout << "Before POP:" << endl;
    browser.display();

    cout << "\nPerforming POP:" << endl;
    browser.pop();

    cout << "\nAfter POP:" << endl;
    browser.displayTop();

    cout << "\nRemaining Browsing History:" << endl;
    browser.display();

    return 0;
}
