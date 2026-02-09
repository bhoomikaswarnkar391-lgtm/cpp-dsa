#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
};

void insertion(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if( head == nullptr){
        head = temp;
        tail = temp;
    }else{
        tail -> next = temp;
        tail = temp;
    }
}

// int maxLen(Node* head){
//     int len = 0;
//     while(head!= nullptr){
//         len++;
//         head = head -> next;
//     }

//     return len;
// }

// Node* midList(Node* head){
//     int getLen = maxLen(head);
//     int ans = getLen/2;

//     Node* temp = head;
//     int cnt = 0;
//     while(cnt < ans){
//         temp = temp -> next;
//         cnt++;
//     }
//     return temp;
// }

Node* midList(Node* head){
    Node* slow = head;
    Node* fast = head;

    if(head == nullptr || head -> next == nullptr)
    return head;

    while(fast -> next!= nullptr && fast -> next -> next != nullptr){
        slow = slow -> next;
        fast = fast ->next -> next;
    }
    return slow;

}

void traverse(Node* head){
    Node* temp = head;
    while (temp != nullptr)
    { 
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
}


int main(){
     Node* head = nullptr;
     Node* tail = nullptr;
    int n ;
    cout<<"ENTER THE SIZE OF THE LIST :";
    cin>>n;
     for(int i=0; i<n; i++){
        int data;
        cin>>data;
        insertion(head, tail, data);
     }
     Node* temp = midList(head);
     cout<<temp->data;
}

