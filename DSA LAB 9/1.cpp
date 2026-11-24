#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    string name;
    int rollNo;
    int marks;
    Node* left;
    Node* right;

    Node(string n, int r, int m){
        name = n;
        rollNo = r;
        marks = m;
        left = NULL;
        right = NULL;
    }
};
class MaxHeap{
public:
    Node* root;

    MaxHeap(){
        root = NULL;
}
    void insert(string n, int r, int m){
        Node* newNode = new Node(n,r,m);

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

        if(parent != NULL && newNode->marks > parent->marks){
            swap(newNode->name,parent->name);
            swap(newNode->rollNo,parent->rollNo);
            swap(newNode->marks,parent->marks);

            heapifyUp(parent);
        }
    }

    void heapifyDown(Node* temp){
        Node* largest = temp;

        if(temp->left != NULL &&
           temp->left->marks > largest->marks)
            largest = temp->left;

        if(temp->right != NULL &&
           temp->right->marks > largest->marks)
            largest = temp->right;

        if(largest != temp){
            swap(temp->name,largest->name);
            swap(temp->rollNo,largest->rollNo);
            swap(temp->marks,largest->marks);

            heapifyDown(largest);
        }
    }
    void deleteRoot(){
        if(root == NULL){
            cout<<"Heap is empty!";
            return;
        }

        cout<<"\nDeleted Student: "<<root->name;
        cout<<"\nMarks: "<<root->marks<<endl;

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
        root->rollNo = last->rollNo;
        root->marks = last->marks;

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

            cout<<"Name: "<<temp->name;
            cout<<" | Roll No: "<<temp->rollNo;
            cout<<" | Marks: "<<temp->marks<<endl;

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
};
int main(){
    MaxHeap h;
    h.insert("Ali",101,85);
    h.insert("Ahmed",102,92);
    h.insert("Usman",103,78);
    h.insert("Bilal",104,95);
    h.insert("Hamza",105,88);
    h.insert("Saad",106,80);
    cout<<"Student Merit List:"<<endl;
    h.display();
    h.deleteRoot();
    cout<<"\nUpdated Merit List:"<<endl;
    h.display();

    return 0;
}

