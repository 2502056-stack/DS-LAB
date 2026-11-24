#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
    int orderID;
    string customerName;
    int amount;
    Node* left;
    Node* right;

    Node(int id,string n,int a){
        orderID = id;
        customerName = n;
        amount = a;
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
    void insert(int id,string n,int a){
        Node* newNode = new Node(id,n,a);

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

        if(parent != NULL && newNode->amount > parent->amount){
            swap(newNode->orderID,parent->orderID);
            swap(newNode->customerName,parent->customerName);
            swap(newNode->amount,parent->amount);

            heapifyUp(parent);
        }
    }
    void heapifyDown(Node* temp){
        Node* largest = temp;

        if(temp->left != NULL &&
           temp->left->amount > largest->amount)
            largest = temp->left;

        if(temp->right != NULL &&
           temp->right->amount > largest->amount)
            largest = temp->right;

        if(largest != temp){
            swap(temp->orderID,largest->orderID);
            swap(temp->customerName,largest->customerName);
            swap(temp->amount,largest->amount);

            heapifyDown(largest);
        }
    }
    int deleteRoot(){
        if(root == NULL)
            return -1;

        int value = root->amount;

        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            return value;
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

        root->orderID = last->orderID;
        root->customerName = last->customerName;
        root->amount = last->amount;

        if(parent->right == last)
            parent->right = NULL;
        else
            parent->left = NULL;

        delete last;

        heapifyDown(root);

        return value;
    }
    void heapSort(){
        int sorted[100];
        int count = 0;
        while(root != NULL){
            sorted[count] = deleteRoot();
            count++;
        }
        cout<<"\nOrder Amounts in Ascending Order:"<<endl;

        for(int i=count-1; i>=0; i--){
            cout<<sorted[i]<<" ";
        }
    }
};
int main(){
    MaxHeap h;
    h.insert(301,"Ali",5000);
    h.insert(302,"Ahmed",3000);
    h.insert(303,"Usman",8000);
    h.insert(304,"Bilal",2000);
    h.insert(305,"Hamza",7000);
    h.insert(306,"Saad",4000);
    h.heapSort();

    return 0;
}

