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

void removeCycle(Node * head){
    if(head==NULL)
        return;
    Node* slow=head; 
    Node * fast = head ; 
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow=head;
            if(fast==head){
                while(fast->next!=head)
                    fast=fast->next;
                fast->next=NULL;
                return;
            }
            else{
                while(slow->next!=fast->next){
                    slow=slow->next;
                    fast=fast->next;
                }
                fast->next=NULL;
                return;
            }
        }        
    }
    return;
}

int main()
{
    
    return 0;
}