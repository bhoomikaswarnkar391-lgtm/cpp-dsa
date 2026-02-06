#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    };
};

//Insertion at head -> new node will be add before the head 
void insertion(Node* &head, int data){
    Node* temp = new Node(data);
    
    temp -> next = head;
    if(head != NULL){
        head -> prev = temp;
    }
        head = temp;
}


//Insertion at tail -> new node will be add after the head 
void insertionTail(Node* &tail, int data){
    Node* temp = new Node(data);
    temp -> prev = tail;
    if(tail != NULL){
        tail -> next = temp;
    }
    tail = temp;
}

//Insertion at Middle -> new node can add at any position 
void insertionMid(Node* & tail, Node* head, int data, int pos){
    int cnt = 1;

    if(pos == 1){
        insertion(head, data);
        return;
    }

    Node* temp = head;

    while(cnt < pos -1 ){
        temp = temp->next;   // move
        cnt++;               // count
    }

    Node* nodeToInsert = new Node(data);   // create ONCE

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

    }



//Traverse a list
void traverse(Node* head){
    
        Node* temp = head;
        while( temp != NULL){
            cout<< temp -> data <<" ";
            temp = temp ->next;            
        }
    cout<<endl;
}


//Finding the lenght of the list size 
int maxLen(Node* head){
    int len = 0;
         Node* temp = head;
        while( temp != NULL){
            len++;
            temp = temp ->next;            
        }
    return len;
}

//Main
int main(){
    int data;
    cout<<"Insert any values for list : ";
    cin>>data;

   Node* head = new Node(data);
   traverse(head);
   Node* tail = head;
   int len = maxLen(head);
   cout<<len;
    int ndata;
   cout<<endl<<"insertion :";
   cin>>ndata;
   insertion(head, ndata);
   traverse(head);
   
   int tddata;
   cout<<"Here's the list of tail :";
   cin>>tddata;
   insertionTail(head,tddata);
   cout<<"head traversing";
   traverse(head);
   cout<<"tail traversing";
   traverse(tail);

   int tdata;
   int po;
   cout<<"Here's the list of mid ele first data then position  :";
   cin>>tdata;
   cin>>po;
   insertionMid(tail,head,tdata, po);
   traverse(head);
   traverse(tail);

 

}