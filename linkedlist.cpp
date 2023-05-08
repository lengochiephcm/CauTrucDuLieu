#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;

}node;
typedef struct list{
    node *Head;
    node *Tail;

}Linkedlist;

node *createNode(int n){
    node *newNode = new node();
    newNode -> data = n;
    newNode -> next = NULL;
    return newNode;
}
void approve(node*head){
    while(head != NULL){
        cout<<head -> data;
        head = head -> next;

    }
}
int count (node *head)
{
    int count1 = 0;
    while(head != NULL){
        ++count1;
        head = head -> next;

    }
}
void front(node**head , int n){
    node *newNode= createNode(n);
    newNode-> next = *head;
}
int main(){
    node*head= NULL;

}