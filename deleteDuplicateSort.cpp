#include <iostream>
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
    if(head == nullptr){
        head = temp;
        tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}

void traverse(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp ->data <<" ";
        temp = temp -> next;
    }
}

Node* deleteDuplicate(Node* head){
    if(head == nullptr || head -> next == nullptr)
    return head;

    Node* curr = head;
    while(curr -> next != nullptr){
        if(curr -> data == curr-> next -> data){
            Node* temp = curr ->next;
            curr -> next = temp -> next;
            delete temp;
        }else{
            curr = curr -> next;
        }
    }
    return head;
}

int main(){
    int n;
    cout<<"ENTER THE NUMBER OF THE LIST : ";
    cin>>n;
    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i=0; i<n; i++){
        int data;
        cin>>data;
        insertion(head, tail, data);
    }

    Node* temp = deleteDuplicate(head);
    traverse(temp);
}

