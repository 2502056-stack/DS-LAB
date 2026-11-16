
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int token;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        token = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == NULL)
            return 0;

        return node->height;
    }

    int getBalance(Node* node) {
        if (node == NULL)
            return 0;

        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* middle = x->right;

        x->right = y;
        y->left = middle;

        y->height = 1 + max(getHeight(y->left),
         getHeight(y->right));

        x->height = 1 + max(getHeight(x->left),
        getHeight(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* middle = y->left;

        y->left = x;
        x->right = middle;

        x->height = 1 + max(getHeight(x->left),
        getHeight(x->right));

        y->height = 1 + max(getHeight(y->left),
        getHeight(y->right));

        return y;
    }

    Node* insertNode(Node* node, int value) {
        if (node == NULL)
            return new Node(value);

        if (value < node->token)
            node->left = insertNode(node->left, value);
        else if (value > node->token)
            node->right = insertNode(node->right, value);
        else
            return node;

        node->height = 1 + max(getHeight(node->left),
          getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->token)
            return rightRotate(node);
        if (balance < -1 && value > node->right->token)
            return leftRotate(node);

        if (balance > 1 && value > node->left->token) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->token) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrder(Node* node) {
        if (node == NULL)
            return;

        inOrder(node->left);
        cout << node->token << " ";
        inOrder(node->right);
    }

    void displayStructure(Node* node, int level) {
        if (node == NULL)
            return;

        displayStructure(node->right, level + 1);

        for (int i = 0; i < level; i++)
            cout << "    ";

        cout << node->token
             << " [h=" << node->height
             << ", BF=" << getBalance(node) << "]\n";

        displayStructure(node->left, level + 1);
    }

    void destroyTree(Node* node) {
        if (node == NULL)
            return;

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    AVLTree() {
        root = NULL;
    }

    ~AVLTree() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void displayInOrder() {
        inOrder(root);
        cout << '\n';
    }

    void displayTree() {
        displayStructure(root, 0);
    }
};

int main() {
    AVLTree hospital;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < 7; i++)
        hospital.insert(tokens[i]);

    cout << "Patient tokens in ascending order (In-order): ";
    hospital.displayInOrder();

    cout << "\nFinal balanced AVL tree\n";
    cout << "(Right subtree appears above each parent; left below.)\n";

    hospital.displayTree();

    return 0;
}

