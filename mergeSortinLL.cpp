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
    if(head == nullptr){
        head = temp;
        tail = temp;
    }else{
        tail -> next = temp;
        tail = temp;
    }
}

void traverse(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
}



Node* mergeSortInLL(Node* l1, Node* l2){
     

}

int main(){
    int n;
    cin>>n;

    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0; i>n; i++){
        int data;
        cin>>data;
        insertion(head, tail, data);
    }

    int m;
    cin>>m;
    Node* head1 = nullptr;
    Node* tail1 = nullptr;

    for(int i=0; i<m; i++){
        int data;
        cin>>data;
        insertion(head1, tail1, data);
    }

    Node* temp = mergeSortInLL(head, head1);
    traverse(temp);

}