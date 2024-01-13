#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int val,Node* next): val(val), next(next){}
    Node(): val(), next(NULL){}
    Node(int val):val(val) ,next(NULL){}
};
Node* sortt(Node* a, Node* b){
    Node* temp1=a;
    Node* temp2=b;
    Node* dummy=new Node();
    Node* temp=dummy;
    while(temp1 || temp2){
        if(temp1 && temp2){
            if(temp1->val<=temp2->val){
                temp->next=new Node(temp1->val);
                temp1=temp1->next;
                temp=temp->next;
            }
            else{
                temp->next=new Node(temp2->val);
                temp2=temp2->next;
                temp=temp->next;
            }
        }
        else if(temp1){
            while(temp1){
                temp->next=new Node(temp1->val);
                temp1=temp1->next;
                temp=temp->next;
            }
        }
        else if(temp2){
            while(temp2){
                temp->next=new Node(temp2->val);
                temp2=temp2->next;
                temp=temp->next;
            }
        }
    }temp=dummy->next;
    delete dummy;
    return temp;
}
class LL{
public:
Node* head;
LL(): head(NULL){}
LL(Node* head): head(head){};
LL(int val){
    head=new Node(val);
}
void add(int val){
    if(!head){
        head=new Node(val);
        return;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=new Node(val);
}
void print(){
    Node* temp=head;
    cout<<"List is: ";
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
};
int main(){
    LL* LinkedList=new LL();
    LinkedList->add(5);
    LinkedList->add(6);
    LinkedList->add(7);
    LinkedList->add(8);
    LinkedList->add(9);
    LinkedList->print();
    cout<<endl;
    Node* dummy=new Node(0,LinkedList->head);
    Node* temp=dummy;
    int n=3;
    while(n){
        temp=temp->next;
        --n;
    }
    cout<<temp->val;
    return 0;
}