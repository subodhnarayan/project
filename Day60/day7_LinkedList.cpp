/*****************************************************************************
           Learning LinkedList

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};


class LL{
    public:
    Node *head;
    LL(){
        head=NULL;
    }
    void insertAtEnd(int x){
        Node *temp=new Node(x);
        cout<<x<<" is inserted at End of LinkedList"<<endl;
        if(head==NULL){
            head=temp;
            return;
        }
        else{
            Node* curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=temp;
        }
        return;
    }
    
    void insertAtFirst(int x){
        Node* temp=new Node(x);
        cout<<x<<" is inserted at first of LinkedList"<<endl;
        if(head==NULL){
            head=temp;
            return;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }
    
    
    void deleteAtLast(){
        if(head==NULL){
            cout<<"No Element exit in linked list"<<endl;
            return;
        }
        if(head->next==NULL){ //only one element in LL
            cout<<head->data<<" is deleted from LinkedList"<<endl;
            delete head;
            head=NULL;
            return;
        }
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        cout<<temp->next->data<<" is deleted from LinkedList"<<endl;
        temp->next=NULL;
    }
    
    void deleteAtFirst(){
        if(head==NULL){
            cout<<"No Element exit in linked list"<<endl;
            return;
        }
        if(head->next==NULL){ //only one element in LL
            cout<<head->data<<" is deleted from LinkedList"<<endl;
            delete head;
            head=NULL;
            return;
        }
        cout<<head->data<<" is deleted from LinkedList"<<endl;
        head=head->next;
        return;
    }
    
    
    void printLL(){
        if(head==NULL){
            cout<<"No Element is present in LinkedList"<<endl;
            return;
        }
        Node* curr=head;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    
    void deleteNode(int val){
        if(head==NULL){
            cout<<"No Element is present in LinkedList"<<endl;
            return;
        }
        if(head->data==val){ //only one element in LL
            cout<<head->data<<" is deleted from LinkedList"<<endl;
            head=head->next;
            return;
        }
       Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Element " << val << " not found in LinkedList" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        cout << nodeToDelete->data << " is deleted from LinkedList" << endl;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
       
    }

};

int main()
{
    LL ll;
    ll.deleteAtLast();
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtFirst(0);
    ll.printLL();
    ll.insertAtEnd(3);
    ll.printLL();
    ll.deleteAtLast();
    ll.printLL();
    ll.deleteAtFirst();
    ll.printLL();
    ll.deleteNode(1);
    ll.printLL();
    return 0;
}