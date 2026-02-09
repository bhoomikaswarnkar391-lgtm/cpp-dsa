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

Node* insertion(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if (head == NULL){
        head = temp;
        tail = temp;
        return tail;
    }
    tail -> next = temp;
    tail = temp;
     
    return tail;
}

Node* mergeSort(Node* list1, Node* list2){
    Node* dummy = new Node(-1);
    Node* tail = dummy;

   while (list1 != NULL && list2 != NULL){
        if(list1 -> data >= list2 -> data){
            tail -> next = list2;
            list2 = list2 -> next;
        }else{
            tail -> next = list1;
            list1 = list1 -> next;
        }
        tail = tail -> next;
    }
    if(list1 != NULL) tail -> next = list1;
    if(list2 != NULL) tail -> next = list2;

    return dummy -> next;

}

void traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" -> ";
        temp = temp -> next;
    }
}


int main(){
int n1,n2;
cin>>n1>>n2;

Node* head1 = NULL;
Node* tail1 = NULL;

Node*head2 = NULL;
Node*tail2 = NULL;
for(int i =0; i<n1; i++){
    int data;
    cin>>data;
    insertion(head1, tail1, data);

}

for(int i =0; i<n2; i++){
    int data;
    cin>>data;
    insertion(head2, tail2, data);
    
}

 Node* head = mergeSort(head1, head2);
 traverse(head);
 
}

