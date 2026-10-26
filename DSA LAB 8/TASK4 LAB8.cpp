#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = right = nullptr;
    }
};

class EmployeeBST {
private:
    Node* root;

    Node* insert(Node* node, int id) {
        if (node == nullptr)
            return new Node(id);

        if (id < node->id)
            node->left = insert(node->left, id);
        else if (id > node->id)
            node->right = insert(node->right, id);

        return node;
    }

    Node* minimum(Node* node) {
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int id) {
        if (node == nullptr)
            return nullptr;

        if (id < node->id) {
            node->left = deleteNode(node->left, id);
        }
        else if (id > node->id) {
            node->right = deleteNode(node->right, id);
        }
        else {
            if (node->left == nullptr &&
                node->right == nullptr) {
                delete node;
                return nullptr;
            }

            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minimum(node->right);
            node->id = temp->id;
            node->right = deleteNode(node->right, temp->id);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->id << " ";
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
    EmployeeBST() {
        root = nullptr;
    }

    ~EmployeeBST() {
        destroy(root);
    }

    void insert(int id) {
        root = insert(root, id);
    }

    void remove(int id) {
        root = deleteNode(root, id);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    int testIDs[] = {50, 30, 70, 20, 40, 60, 80};
    EmployeeBST tree1;
    for (int id : testIDs)
        tree1.insert(id);

    cout << "Delete leaf node 20:\n";
    tree1.remove(20);
    tree1.display();


    EmployeeBST tree2;
    for (int id : testIDs)
        tree2.insert(id);

    tree2.remove(20); 
    cout << "Delete node 30 with one child:\n";
    tree2.remove(30);
    tree2.display();

    EmployeeBST tree3;
    for (int id : testIDs)
        tree3.insert(id);

    cout << "Delete node 50 with two children:\n";
    tree3.remove(50);
    tree3.display();

    return 0;
}
