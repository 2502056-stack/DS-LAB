#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {

public:
    string category;
    Node* left;
    Node* right;

    Node(string value) {

    category = value;

    left = NULL;
    right = NULL;

    }

};

 

void BFS(Node* root) {

    if (root == NULL)

        return;

 

    queue<Node*> q;

    q.push(root);

 

    while (!q.empty()) {

        Node* current = q.front();

        q.pop();

 

        cout << current->category << " ";

 

        if (current->left != NULL)

            q.push(current->left);

 

        if (current->right != NULL)

            q.push(current->right);

    }

}

 

void destroyTree(Node* root) {

    if (root == NULL)

        return;

    destroyTree(root->left);

    destroyTree(root->right);

    delete root;

}

 

int main() {

    Node* electronics = new Node("Electronics");

    Node* clothing = new Node("Clothing");

    Node* mobiles = new Node("Mobiles");

    Node* laptops = new Node("Laptops");

    Node* men = new Node("Men");

    Node* women = new Node("Women");

    Node* accessories = new Node("Accessories");

 

    electronics->left = clothing;

    electronics->right = mobiles;

    clothing->left = laptops;

    clothing->right = men;

    mobiles->left = women;

    mobiles->right = accessories;

 

    cout << "Categories in Breadth-First (BFS) order:\n";

    BFS(electronics);

    cout << '\n';

 

    destroyTree(electronics);

    return 0;

}
