#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string folderName) {
        folder = folderName;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node* root) {
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->folder << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == NULL) return;

    cout << root->folder << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->folder << " ";
}

void destroyTree(Node* root) {
    if (root == NULL) return;

    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node("C_Drive");

    Node* documents = new Node("Documents");
    Node* pictures = new Node("Pictures");

    Node* assignments = new Node("Assignments");
    Node* reports = new Node("Reports");

    Node* family = new Node("Family_Photos");
    Node* travel = new Node("Travel_Photos");

    root->left = documents;
    root->right = pictures;

    documents->left = assignments;
    documents->right = reports;

    pictures->left = family;
    pictures->right = travel;

    cout << "In-order (Left, Root, Right): ";
    inOrder(root);

    cout << "\nPre-order (Root, Left, Right): ";
    preOrder(root);

    cout << "\nPost-order (Left, Right, Root): ";
    postOrder(root);

    cout << '\n';

    destroyTree(root);

    return 0;
}
