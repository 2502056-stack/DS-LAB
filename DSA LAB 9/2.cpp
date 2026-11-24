#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
    string name;
    int patientID;
    int priority;
    Node* left;
    Node* right;

    Node(string n,int id,int p){
        name = n;
        patientID = id;
        priority = p;
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
    void insert(string n,int id,int p){
        Node* newNode = new Node(n,id,p);

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

        if(parent != NULL && newNode->priority > parent->priority){
            swap(newNode->name,parent->name);
            swap(newNode->patientID,parent->patientID);
            swap(newNode->priority,parent->priority);

            heapifyUp(parent);
        }
    }
    void heapifyDown(Node* temp){
        Node* largest = temp;

        if(temp->left != NULL &&
           temp->left->priority > largest->priority)
            largest = temp->left;

        if(temp->right != NULL &&
           temp->right->priority > largest->priority)
            largest = temp->right;

        if(largest != temp){
            swap(temp->name,largest->name);
            swap(temp->patientID,largest->patientID);
            swap(temp->priority,largest->priority);

            heapifyDown(largest);
        }
    }
    void deleteRoot(){
        if(root == NULL){
            cout<<"Heap is empty!";
            return;
        }

        cout<<"\nPatient Treated: "<<root->name;
        cout<<"\nPatient ID: "<<root->patientID;
        cout<<"\nPriority: "<<root->priority<<endl;

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
        root->patientID = last->patientID;
        root->priority = last->priority;

        if(parent->right == last)
            parent->right = NULL;
        else
            parent->left = NULL;

        delete last;

        heapifyDown(root);
    }
    void display(){
        if(root == NULL){
            cout<<"No patients available!";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            cout<<"Name: "<<temp->name;
            cout<<" | ID: "<<temp->patientID;
            cout<<" | Priority: "<<temp->priority<<endl;

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    void nextPatient(){
        if(root != NULL){
            cout<<"\nNext Patient: "<<root->name;
            cout<<" | Priority: "<<root->priority<<endl;
        }
    }
};
int main(){
    MaxHeap h;
    h.insert("Ali",201,3);
    h.insert("Ahmed",202,5);
    h.insert("Usman",203,2);
    h.insert("Bilal",204,9);
    h.insert("Hamza",205,6);
    h.insert("Saad",206,4);

    cout<<"Hospital Emergency List:"<<endl;
    h.display();
    h.deleteRoot();

    cout<<"\nUpdated Patient List:"<<endl;
    h.display();
    h.nextPatient();

    return 0;
}

