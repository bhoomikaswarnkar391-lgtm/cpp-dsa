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
//reverse the order of the list 
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

//check if it;s palindrom via two pointers slow and fast 
bool palindrome(Node* head){
    if(head == NULL || head-> next != NULL)
    return true;

    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast -> next == NULL){
        slow = slow->next;
        fast = fast -> next -> next;
    }

   Node* secondHalf = reverse(slow);
   Node* firstHalf = head;

   while(secondHalf != NULL){
    if(secondHalf -> data != firstHalf->data)
    return false;

    secondHalf = secondHalf ->next;
    firstHalf = firstHalf -> next;
   }
    return true;
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
bool hd = palindrome(head);
if(hd)
cout<<"yes";
else
cout<<"no";
//traverse(head);
}