#include <iostream>
using namespace std;

class Node {
public:
    int productID;
    Node* left;
    Node* right;

    Node(int id) {
        productID = id;
        left = right = nullptr;
    }
};

class Inventory {
private:
    Node* root;

    Node* insertNode(Node* node, int id) {
        if (node == nullptr)
            return new Node(id);

        if (id < node->productID)
            node->left = insertNode(node->left, id);
        else if (id > node->productID)
            node->right = insertNode(node->right, id);
        else
            cout << "Duplicate product ID not allowed.\n";

        return node;
    }

    bool searchNode(Node* node, int id) {
        if (node == nullptr)
            return false;

        if (node->productID == id)
            return true;

        if (id < node->productID)
            return searchNode(node->left, id);

        return searchNode(node->right, id);
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int id) {
        if (node == nullptr)
            return nullptr;

        if (id < node->productID)
            node->left = deleteNode(node->left, id);
        else if (id > node->productID)
            node->right = deleteNode(node->right, id);
        else {
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

            Node* temp = findMin(node->right);
            node->productID = temp->productID;
            node->right = deleteNode(node->right, temp->productID);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->productID << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->productID << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->productID << " ";
    }

    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    Inventory() {
        root = nullptr;
    }

    ~Inventory() {
        destroy(root);
    }

    void insert(int id) {
        root = insertNode(root, id);
    }

    void search(int id) {
        if (searchNode(root, id))
            cout << "Product Found.\n";
        else
            cout << "Product Not Found.\n";
    }

    void remove(int id) {
        if (!searchNode(root, id)) {
            cout << "Product not found.\n";
            return;
        }

        root = deleteNode(root, id);
        cout << "Product deleted successfully.\n";
    }

    void displayInorder() {
        if (root == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        if (root == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        if (root == nullptr) {
            cout << "Inventory is empty.\n";
            return;
        }
        postorder(root);
        cout << endl;
    }
};

int main() {
    Inventory store;
    int choice, id;

    do {
        cout << "\n===== PRODUCT INVENTORY =====\n";
        cout << "1. Insert Product ID\n";
        cout << "2. Search Product ID\n";
        cout << "3. Delete Product ID\n";
        cout << "4. In-order Traversal\n";
        cout << "5. Pre-order Traversal\n";
        cout << "6. Post-order Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            store.insert(id);
            break;

        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;
            store.search(id);
            break;

        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;
            store.remove(id);
            break;

        case 4:
            cout << "In-order: ";
            store.displayInorder();
            break;

        case 5:
            cout << "Pre-order: ";
            store.displayPreorder();
            break;

        case 6:
            cout << "Post-order: ";
            store.displayPostorder();
            break;

        case 7:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
