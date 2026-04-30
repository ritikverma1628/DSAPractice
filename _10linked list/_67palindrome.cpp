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
    };

bool palindrome(Node* head){
    List l;
    Node* temp = head;
    while(temp!=NULL){
        if(l.head==NULL){
            Node * newNode = new Node(temp->data);
            l.head=l.tail = newNode;
            temp=temp->next;
        }
        else{
            Node * newNode = new Node(temp->data);
            newNode->next = l.head;
            l.head = newNode;
            temp=temp->next;
        }
    }
    temp = head;
    Node *temp1 = l.head;
    while(temp!=NULL){
        if(temp->data!=temp1->data)
            return false;

        temp = temp->next;
        temp1 = temp1->next;
    }
    return true;
}

int main()
{
    List l ;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(2);
    l.pushBack(0);
    cout<<palindrome(l.head);
    return 0;
}