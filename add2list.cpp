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

Node* insertion(Node* &head, Node* &tail,int data){
    Node* temp = new Node(data);
    if(head == nullptr){
        head = temp;
        tail = temp;
         
    }else{
        tail -> next = temp;
         tail = temp;
    }
     return head;
}

void traverse(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp ->data <<" ";
        temp = temp -> next;
    }
}

// Node* reverse(Node* head){
//     Node* curr = head;
//     Node* prev = nullptr;
//     Node* next = nullptr;

//     while(curr != nullptr){
//         next = curr -> next;
//         curr -> next = prev;
//         prev = curr; 
//         curr = next;
//     }
//     return prev;
// }

Node* addTwoNum(Node* first, Node* second){
     Node* head = nullptr;
    Node* tail = nullptr;
   
    int carry = 0;
     while(first != nullptr || second != nullptr || carry != 0){
        int sum =0;
        if(first != nullptr){
            sum += first->data;
            first = first-> next;
        }

        if(second != nullptr){
            sum += second->data;
            second = second-> next;
        }

        sum += carry;
        carry = sum /10;
        int digit = sum % 10;


      insertion(head, tail, digit);

     }
     
return head;
}


int main(){
    int n;
    cout<<"size of first list and second list ";
    cin>>n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i=0; i<n; i++){
        int data;
        cin>>data;
        insertion(head, tail, data);
    }

    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    for(int j=0; j<n; j++){
        int data;
        cin>>data;
        insertion(head2, tail2, data);
    }

    Node* temp = addTwoNum(head, head2);
    traverse(temp);

}
