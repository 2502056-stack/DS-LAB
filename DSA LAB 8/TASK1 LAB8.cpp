#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class FamilyTree {
private:
    Node* root;

    void display(Node* node) {
        if (node == nullptr)
            return;

        cout << "Person: " << node->name << endl;
        cout << "Left Child: ";
        if (node->left != nullptr)
            cout << node->left->name;
        else
            cout << "None";

        cout << "\nRight Child: ";
        if (node->right != nullptr)
            cout << node->right->name;
        else
            cout << "None";

        cout << "\n\n";

        display(node->left);
        display(node->right);
    }

    void destroy(Node* node) {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    FamilyTree() {
        root = nullptr;
    }

    ~FamilyTree() {
        destroy(root);
    }

    void createTree() {
        root = new Node("Grandfather");
        root->left = new Node("Father");
        root->right = new Node("Uncle");
        root->left->left = new Node("Ali");
        root->left->right = new Node("Sara");
        root->right->left = new Node("Ahmed");
        root->right->right = new Node("Ayesha");
    }

    void displayTree() {
        display(root);
    }
};

int main() {
    FamilyTree family;

    family.createTree();
    family.displayTree();

    return 0;
}
