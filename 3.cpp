#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL){}
    Node(int vL): val(vL), next(NULL){}
};
int main(){
   Node n1=Node(1);
   Node* n2=new Node(2);
   Node n3=Node(3);
   Node* n4=new Node(4);
   n1.next=n2;
   n2->next=&n3;
   n3.next=n4;
   cout<<n1.next->next->next->val<<" "<<n2->next->next->val<<" "<<n3.next->val<<" "<<n4->val;
   return 0;
}