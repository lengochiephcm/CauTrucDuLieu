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
void create(Linkedlist &l){
    l.Head =NULL;
    l.Tail= NULL;

}
node*createNode(int n){
    node *Node = new node();
    if(Node == NULL){
        cout<<"\n Khong du du lieu cap phat!!!";
        return NULL;

    }
    Node -> data =n;
    Node -> next = NULL;
    return Node;

}
void addFirstposition(Linkedlist&l,node*Node){
    if(l.Head == NULL){
        l.Head = l.Tail = Node;

    }
    else{
        Node -> next = l.Head;
        l.Head =Node;

    }
}
void addLastposition(Linkedlist&l,node*Node){
    if(l.Head == NULL){
        l.Head = l.Tail = Node;

    }
    else{
        l.Tail -> next = Node ;
        l.Tail = Node;


    }
}

void printoutLinkedlist(Linkedlist l){
    for(node *k =l.Head;k !=NULL; k = k->next)
    {
        cout << k ->data<< " ";
    }
}
int main(){
    
    Linkedlist l;
    create(l);
    int n;
    cout<<"\n Nhap gia tri cua mang: ";
    cin>>n;
    if( n <1){
        while(n<1){
            cout<<"\n Vui long nhap gia tri cua mang lon hon 1: ";
            cin >>n;

        }
    }
    for(int i =0; i<n ; i++){
        int x;
        cout<<"\n Nhap gia tri cua thanh phan  "<<i<<": ";
        cin>>x;
        node*Node = createNode(x);
        addFirstposition(l,Node);
        addLastposition(l,Node);
    }
    printoutLinkedlist(l);
    
}