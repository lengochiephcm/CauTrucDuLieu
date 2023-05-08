#include<iostream>
#include<math.h>
using namespace std;

typedef struct node{
    int data;
    node*next;
}node;

typedef struct linkedlist{
    node* head;
    node* tail;

}list;
int createLinkedList(list &l){
    l.head = l.tail = NULL;
}
int isEmpty(list l){
    return(l.head == NULL);

}
node * createNode(int n){
    node*p= new node;
    if(p== NULL){
        cout<<"\n Khong du vung nho cap phat";

    }
    p->data = n;
    p-> next = NULL;
    return p;
}
void addFirstPosition(list &l, node*p){
    if(isEmpty(l)){
        l.head = l.tail = p;
    }
    p-> next = l.head ;
    l.head  = p;
}
void addLastPosition(list&l, node *p){
    if(isEmpty(l)){
        l.head = l.tail = p;
    }
    l.tail -> next = p;
    l.tail = p;
}
void inputList(list &l){
    int n,x;
    
    cout<<"\n Nhap gia tri cua danh sach lien ket: ";
    cin>>n;
    if(n <1 ){
        while(n<1 ){
        cout<<"\n Vui long nhap lai gia tri cua danh sach: ";
        cin>>n;
    }}
    
    for(int i=0; i < n; i++){
        cout<<"\n Nhap phan tu thu "<<i+1<<" :";
        cin>>x;
        node*p = createNode(x);
        addLastPosition(l,p);
    }
}
void printOutList(list l){
    cout<<"\n Danh sach vua nhap: ";
    for(node* k = l.head ; k != NULL; k = k-> next){
        cout<<k-> data<<" ";

    }
}
bool isPrime(int n){
    if(n < 2)
    return false;
    else if(n > 2)
    {
        if ( n % 2== 0)
        return false;
        for(int i =3 ;i < sqrt((float)n); i+=2){
            if( n % i == 0)
            return false;
        }
    }
    return true;

}
float averagePrime(list l){
    int count = 0;
    float sum = 0;
    
    for(node *k = l.head ; k != NULL; k =k -> next){
        {
        if(isPrime(k->data)){
            count++;
            sum += k->data;
        }
        }
    
    }
    cout<<"\n "<<sum/count;
}
float squareRoot(list l){
    int count = 0;
    double root;
    int multiply = 1;
    for(node *k = l.head ; k != NULL; k = k -> next){
        count ++;
        if(k -> data > 0)
        multiply *= k-> data;
    }
    root =sqrt((double)multiply)/ count;
    cout<<"\n Can bac 2 cua ai chia n : "<< root;
}
float rateNegaDivide(list l){
    double nega = 0.0;
    double posi = 1.0;
    double rate;
    for(node *k = l.head ; k != NULL; k = k -> next){
        if(k -> data < 0){
            nega += k-> data;
            
        }
        else if (k -> data > 1){
            posi *= k-> data;
    }
    
}
    rate = nega * ( -1 )/ posi;
    cout<<"\n"<<nega * (-1);
    cout<<"\n"<<posi;
    cout<<"\n"<<rate;
    
}
int main(){
    list l;
    createLinkedList(l);
    inputList(l);
    // printOutList(l);
    // averagePrime(l);
    // squareRoot(l);
    rateNegaDivide(l);   
}