#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    
    Node(int val){
        data=val;
        next=NULL;
    }

};

class List{
    public:
        Node* head ;
        Node * tail ;

        List(){
            head = NULL;
            tail = NULL;
        }

        ~List(){
            while(head!=NULL){
                Node* temp = head->next;
                delete head;
                head=temp;          
            }
        }

        void pushBack(int value){
            Node * newNode = new Node(value);
            if(head==NULL)
                head=tail=newNode;
            else
                {tail->next=newNode;
                tail=newNode;}
        }

        void pushFront(int value){
            Node * newNode = new Node(value);

            if(head==NULL)
                head=tail=newNode;
            else
                {newNode->next = head;
                head=newNode;}
        }
};

void printLL(Node* head){
    Node * temp = head;
    while(temp!=NULL)
        {cout<<temp->data<<" ";
        temp=temp->next;}
}

bool hasCycle(Node * head){
    if(head==NULL || head->next==NULL)
        return false;
    Node* slow = head; 
    Node * fast = head; 
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow = slow->next;
        if(fast==slow)
            return true;
    }
    return false;
}

int main()
{
    List l ; 
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(4);
    l.tail->next=l.head;
    cout<<hasCycle(l.head);
    return 0;
}