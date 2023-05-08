#include <iostream>
#include <math.h>
using namespace std;
typedef struct node {
    int data ;
    struct node *next;

}node;
typedef struct linkedlist{
    node *head;
    node *tail;

}list;
int createLinkedlist(list &l){
    l.head = l.tail = NULL;

}
int isEmpty(list &l){
    return(l.head == NULL);
}
node *createNode(int n){
    node * p = new node;
    if(p == NULL){
        cout<<"\n Khong du bo nho cap phat...";

    }
    p-> data = n;
    p-> next = NULL;

    return p;

}
bool isPrime(int n){
    if(n < 2 ) return false;
    else if( n > 2){
        if ( n % 2 == 0) return false;
        for(int i = 3; i < sqrt((float)n); i += 2){
            if( n % i ==0)return false;

        }
   }
    return true;
}
void addFirstPosition(list &l, node *p){
    if(isEmpty(l)){
            l.head = l.tail = p;
    }
    p-> next = l.head;
    l.head = p;

}
void addLastPosition(list &l, node *p){
    if (isEmpty(l)){
        l.head = l.tail = p;
    }
    l.tail -> next = p;
    l.tail = p;
    
}
int inputList(list &l){
    int n,x;
    cout<<"\n Nhap do lon cua danh sach lien ket: ";
    cin >>n;
    for( int i =0; i < n ; i ++){
        cout<<"\n Nhap so nguyen to thu "<< i+1<<": ";
        cin >>x;
        if(isPrime(x)){
            node *p = createNode(x);
            addLastPosition(l,p);
        }
        else{
            while(isPrime(x) == false){
            cout<<"\n Vui long nhap lai gia tri la so nguyen to: ";
            cin>>x;
            node *p = createNode(x);
            addLastPosition(l,p);

            }
        }
    


        
    }

}
void printOutLinkedList(list l){
    cout<<"\n Danh sach vua nhap: ";
    for(node *k = l.head ; k != NULL; k = k -> next){
        cout<<k-> data<<" ";
    }
}
void deleteList(list &l){
    for(node *k = l.head ; k != NULL; k = k -> next){
        delete k;
    }
}
int main(){
    list l;
    createLinkedlist(l);
    inputList(l);
    printOutLinkedList(l);
    system("pause");
    deleteList(l);
}