
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string memberName) {
        name = memberName;
        left = NULL;
        right = NULL;
    }
};

void display(Node* root) {
    if (root == NULL)
        return;

    cout << "Member: " << root->name << '\n';

    cout << "Left child: ";
    if (root->left != NULL)
        cout << root->left->name << '\n';
    else
        cout << "None\n";

    cout << "Right child: ";
    if (root->right != NULL)
        cout << root->right->name << "\n\n";
    else
        cout << "None\n\n";

    display(root->left);
    display(root->right);
}

void destroyTree(Node* root) {
    if (root == NULL)
        return;

    destroyTree(root->left);
    destroyTree(root->right);

    delete root;
}

int main() {
    Node* hod = new Node("Dr. Ahmed - HOD");
    Node* coordinator1 = new Node("Ms. Sara - Coordinator");
    Node* coordinator2 = new Node("Mr. Bilal - Coordinator");
    Node* faculty1 = new Node("Mr. Ali - Faculty");
    Node* faculty2 = new Node("Ms. Hina - Faculty");
    Node* faculty3 = new Node("Mr. Usman - Faculty");
    Node* faculty4 = new Node("Ms. Ayesha - Faculty");

    hod->left = coordinator1;
    hod->right = coordinator2;

    coordinator1->left = faculty1;
    coordinator1->right = faculty2;

    coordinator2->left = faculty3;
    coordinator2->right = faculty4;

    cout << "UNIVERSITY DEPARTMENT HIERARCHY\n\n";

    display(hod);

    destroyTree(hod);

    return 0;
}

