#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string song;
    Node* next;

    Node(string name) {
        song = name;
        next = NULL;
    }
};

int main() {
    Node* n1 = new Node("STRESSED OUT");
    Node* n2 = new Node("ROXANNE");
    Node* n3 = new Node("BAD BLOOD");
    Node* n4 = new Node("GOOD BYES");
    Node* n5 = new Node("BABY");


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1;

    Node* current = n1;

    cout << "Music Playlist:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << current->song << endl;
        current = current->next;
    }
    cout << "\nPlaying Playlist for 2 Rounds:" << endl;

    current = n1;

    for (int i = 1; i <= 10; i++) {
        cout << "Playing: " << current->song << endl;
        current = current->next;
    }

    return 0;
}
