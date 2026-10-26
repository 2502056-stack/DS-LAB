#include <iostream>
using namespace std;

class Node {
public:
    int rollNo;
    Node* left;
    Node* right;

    Node(int value) {
        rollNo = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->rollNo)
            node->left = insert(node->left, value);
        else if (value > node->rollNo)
            node->right = insert(node->right, value);
        else
            cout << "Duplicate roll number!\n";

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->rollNo << " ";
        inorder(node->right);
    }

    void destroy(Node* node) {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        destroy(root);
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST students;

    int rolls[] = {45, 25, 65, 15, 35, 55, 75};

    for (int i = 0; i < 7; i++)
        students.insert(rolls[i]);

    int value;

    for (int i = 1; i <= 2; i++) {
        cout << "Enter additional roll number " << i << ": ";
        cin >> value;
        students.insert(value);
    }

    cout << "Roll numbers in ascending order: ";
    students.display();

    return 0;
}
