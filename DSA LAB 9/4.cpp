#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
    string name;
    int medicineID;
    int expiryDate;
    Node* left;
    Node* right;

    Node(string n,int id,int date){
        name = n;
        medicineID = id;
        expiryDate = date;
        left = NULL;
        right = NULL;
    }
};
class MinHeap{
public:
    Node* root;

    MinHeap(){
        root = NULL;
    }
    void insert(string n,int id,int date){
        Node* newNode = new Node(n,id,date);

        if(root == NULL){
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp->left == NULL){
                temp->left = newNode;
                break;
            }
            else
                q.push(temp->left);

            if(temp->right == NULL){
                temp->right = newNode;
                break;
            }
            else
                q.push(temp->right);
        }

        heapifyUp(newNode);
    }
    void heapifyUp(Node* newNode){
        Node* parent = NULL;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp->left == newNode || temp->right == newNode){
                parent = temp;
                break;
            }

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }

        if(parent != NULL && newNode->expiryDate < parent->expiryDate){
            swap(newNode->name,parent->name);
            swap(newNode->medicineID,parent->medicineID);
            swap(newNode->expiryDate,parent->expiryDate);

            heapifyUp(parent);
        }
    }
    void heapifyDown(Node* temp){
        Node* smallest = temp;

        if(temp->left != NULL &&
           temp->left->expiryDate < smallest->expiryDate)
            smallest = temp->left;

        if(temp->right != NULL &&
           temp->right->expiryDate < smallest->expiryDate)
            smallest = temp->right;

        if(smallest != temp){
            swap(temp->name,smallest->name);
            swap(temp->medicineID,smallest->medicineID);
            swap(temp->expiryDate,smallest->expiryDate);

            heapifyDown(smallest);
        }
    }
    void deleteRoot(){
        if(root == NULL){
            cout<<"Heap is empty!";
            return;
        }

        cout<<"\nDeleted Medicine: "<<root->name;
        cout<<"\nMedicine ID: "<<root->medicineID;
        cout<<"\nExpiry Date: "<<root->expiryDate<<endl;

        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            return;
        }

        queue<Node*> q;
        q.push(root);

        Node* last = root;
        Node* parent = NULL;

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp->left != NULL){
                parent = temp;
                last = temp->left;
                q.push(temp->left);
            }

            if(temp->right != NULL){
                parent = temp;
                last = temp->right;
                q.push(temp->right);
            }
        }

        root->name = last->name;
        root->medicineID = last->medicineID;
        root->expiryDate = last->expiryDate;

        if(parent->right == last)
            parent->right = NULL;
        else
            parent->left = NULL;

        delete last;

        heapifyDown(root);
    }
    void display(){
        if(root == NULL){
            cout<<"Heap is empty!";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            cout<<"Medicine: "<<temp->name;
            cout<<" | ID: "<<temp->medicineID;
            cout<<" | Expiry Date: "<<temp->expiryDate<<endl;

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
};
int main(){
    MinHeap h;
    h.insert("Panadol",401,20270315);
    h.insert("Brufen",402,20270120);
    h.insert("Calpol",403,20270410);
    h.insert("Augmentin",404,20261215);
    h.insert("Disprin",405,20270210);
    h.insert("Arinac",406,20270525);
    cout<<"Medicine Expiry Heap:"<<endl;
    h.display();
    h.deleteRoot();
    cout<<"\nUpdated Medicine Heap:"<<endl;
    h.display();

    return 0;
}

