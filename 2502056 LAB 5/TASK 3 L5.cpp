#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string player;
    Node* next;

    Node(string name) {
        player = name;
        next = NULL;
    }
};

int main() {
    Node* n1 = new Node("Ali");
    Node* n2 = new Node("Ahmed");
    Node* n3 = new Node("Usman");
    Node* n4 = new Node("Hamza");
    Node* n5 = new Node("Bilal");

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1;

    string name;

    cout << "Players: Ali, Ahmed, Usman, Hamza, Bilal" << endl;

    cout << "\nWhose turn is it? ";
    cin >> name;

    Node* current = n1;
    bool found = false;

    for (int i = 0; i < 5; i++) {
        if (current->player == name) {
            found = true;

            cout << "Current turn: " << current->player << endl;
            cout << "Next turn: " << current->next->player << endl;

            break;
        }

        current = current->next;
    }

    if (found == false) {
        cout << "Player not found!" << endl;
    }

    return 0;
}
