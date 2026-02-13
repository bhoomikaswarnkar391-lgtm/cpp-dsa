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
 

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = nullptr;
    Node* nextd = nullptr;

    while(curr != nullptr){
        nextd = curr -> next;
        curr ->next = prev;
        prev = curr;
        curr = nextd;
    }
    return prev;
}
 
Node* sum(Node* l1, Node* l2){
    Node* head = nullptr;
    Node* tail = nullptr;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr || carry != 0){
        int sum =0;
        if(l1 != nullptr ){
            sum += l1->data;
            l1 = l1->next;
        }

        if(l2 != nullptr ){
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum/10;
        int digit = sum %10;
        insertion(head, tail,digit);
    }
    return head;
}

Node* addTwoList(Node* l1, Node* l2){
    Node* temp1 = reverse(l1);
    Node* temp2 = reverse(l2);

    Node* temp = sum(temp1, temp2);

    temp = reverse(temp);
    return temp;
}

void traverse(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    int n;
    cin>>n;

    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0; i<n; i++){
        int data;
        cin>>data;
        insertion(head, tail, data);
    }

    int m ;
    cin>>m;

    Node* head2 = nullptr;
    Node* tail2 = nullptr;
       for(int i=0; i<m; i++){
        int data;
        cin>>data;
        insertion(head2, tail2, data);
    }

    Node* temp = addTwoList(head, head2);
    traverse(temp);

}

