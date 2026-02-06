#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertion(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
   
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    tail -> next = temp;
    tail = temp;
 
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* nextd = NULL;

    while(curr  != NULL){
        nextd = curr -> next ;
        curr -> next = prev;
        prev = curr;
        curr = nextd;
    }
return prev;
}

void traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
cout<<endl;
}


int main(){
int n;
cout<<"Enter how many numbers you want in list : ";
cin>>n;
 
Node* head = NULL;
Node* tail = NULL;

cout<<"Enter those number :";
for(int i=0; i<n; i++){
    int data ; 
    
    cin>>data;
    insertion(head, tail ,data);
}
head = reverse(head);
traverse(head);
}