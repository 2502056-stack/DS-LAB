#include <iostream>
using namespace std;

class Node {
public:
    int bookID;
    Node* left;
    Node* right;

    Node(int id) {
        bookID = id;
        left = right = nullptr;
    }
};

class Library {
private:
    Node* root;

    Node* insert(Node* node, int id) {
        if (node == nullptr)
            return new Node(id);

        if (id < node->bookID)
            node->left = insert(node->left, id);
        else if (id > node->bookID)
            node->right = insert(node->right, id);

        return node;
    }

    void destroy(Node* node) {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    Library() {
        root = nullptr;
    }

    ~Library() {
        destroy(root);
    }

    void insertBook(int id) {
        root = insert(root, id);
    }

    void searchBook(int id) {
        Node* current = root;
        int comparisons = 0;

        while (current != nullptr) {
            comparisons++;

            if (current->bookID == id) {
                cout << "Book Found\n";
                cout << "Comparisons: " << comparisons << endl;
                return;
            }

            if (id < current->bookID)
                current = current->left;
            else
                current = current->right;
        }

        cout << "Book Not Found\n";
        cout << "Comparisons: " << comparisons << endl;
    }
};

int main() {
    Library library;

    int ids[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        library.insertBook(ids[i]);

    int id;
    cout << "Enter book ID to search: ";
    cin >> id;

    library.searchBook(id);

    return 0;
}
