#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL ;
    };
};

//Insertion at Begining 
void insertAtB(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

//Insertion at End
void insertAtE(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

//Insertion at Middle
void insertMid(int pos, Node* &head, int data){
    if(pos == 1){
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
        return ;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < pos-1){
        temp = temp -> next;
        cnt++;
    }

    Node* insertNode = new Node(data);
    insertNode -> next = temp -> next;
    temp -> next = insertNode;


}

//Deletion of node at any position
void deletion(int pos, Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
    int cnt =1;
        while(cnt < pos){
        prev = curr;
        curr = curr->next;
        cnt++;
        }
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
    }
}

//Traversing the list 
void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<endl;
        temp = temp -> next;
    }
}


//Main 
int main(){

    Node* n1 = new Node(10);
    Node* tail = n1;
     int data;
     cout<<"insert element to put inside the node : -";
    cin>>data;
    cout<<"head list "<<endl;
    insertAtB(n1, data);
    printList(n1);
    cout<<"tail list ";
    insertAtE(tail, data);
    printList(n1);
    int pos ; 
    cout<<"give the postition for the mid insertion :";
    cin>>pos;
    int middata;
    cin>>middata;
    insertMid(pos,n1,middata);
    cout<<"here's the list ";
    printList(n1);
    int posDel;
    cout<<"here you can delete any node!! Enter the position :" ;
    cin>>posDel;
    deletion(posDel, n1);
    printList(n1);
}