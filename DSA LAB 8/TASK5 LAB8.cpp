#include <iostream>
using namespace std;

class Node {
public:
    int patientID;
    Node* left;
    Node* right;

    Node(int id) {
        patientID = id;
        left = right = nullptr;
    }
};

class HospitalBST {
private:
    Node* root;

    Node* insert(Node* node, int id) {
        if (node == nullptr)
            return new Node(id);

        if (id < node->patientID)
            node->left = insert(node->left, id);
        else if (id > node->patientID)
            node->right = insert(node->right, id);

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->patientID << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->patientID << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->patientID << " ";
    }

    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    HospitalBST() {
        root = nullptr;
    }

    ~HospitalBST() {
        destroy(root);
    }

    void insert(int id) {
        root = insert(root, id);
    }

    void displayTraversals() {
        cout << "In-order: ";
        inorder(root);

        cout << "\nPre-order: ";
        preorder(root);

        cout << "\nPost-order: ";
        postorder(root);

        cout << "\nIn-order gives ascending order.\n";
    }
};

int main() {
    HospitalBST hospital;
    int ids[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        hospital.insert(ids[i]);

    hospital.displayTraversals();

    return 0;
}
