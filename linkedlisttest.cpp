#include <iostream>
#include <math.h>

using namespace std;

typedef struct node {
    double data ;
    node * next;
}node;
typedef struct list{
    node*head ;
    node*tail;
}list;
void createList(list &l){
    l.head = l.tail = NULL;
}

int isEmpty(list l){
    return(l.head == NULL);
}
node *createNode(double n){
    node * p= new node ;
    if ( p == NULL)
    cout<<"\n Khong du bo nho cap phat";
    p-> data  = n;
    p -> next = NULL;
    return p;
}
void addLastPos(list &l, node*p){
    if(isEmpty(l)){
        l.head = l.tail = p;
    }
    l.tail -> next = p;
    l.tail = p;
}
void enterList(list &l){
    double n,x;
    cout<<"Nhap do lon cua danh sach: ";
    cin>>n;
    if(n<1){
        while(n<1){
            cout<<"\n Vui long nhap gia tri mang lon hon 1: ";
            cin>>n;

        }
    }
    for(int i =0 ;i < n; i++){
        cout<<"\n Nhap gia tri thu "<<i+1<<": ";
        cin>>x;
        node*p = createNode(x);
        addLastPos(l,p);
    }

}
void printOutList(list l){
    cout<<"\n Danh sach da nhap: ";
    for(node *k = l.head ; k != NULL; k =k -> next){
        cout<<k-> data<<" ";
    }

}
bool isPrime(int n){
    if(n < 0){
        n = n * (-1);
    }
    if(n < 2) return false;
   
    for(int i = 2 ; i <= sqrt((float)n); i +=1){
        if(n % i == 0)
            return false;
        }
        return true;

    


}
void caculatePrime(list l){
    float sum = 0;
    int count =0;
    for(node*k =l.head ; k !=NULL ; k =k -> next){
        if(isPrime(k->data)){
            count ++;
            cout<<"\nSo nguyen to: "<<k-> data;
            sum += k-> data;
        }
    }
    cout<<" \n tong: "<<sum/count;
}
int get2NumDemical(double n){
    if ( n < 1 )
    n = n * (-1);
    int count =0;
    int x = int (n);
    double k = n - x;
    do{
        k = k * 10;
      
        count ++;
    
    }while( count <2 );
      if( int(k) % 10 == 0)
        {
            k = k / 10;
        }
    return int(k);
    cout<<"\n"<<n;

}
void isDemicalPrime(list l){
    int count =0;
    for(node *k = l.head ; k != NULL; k = k -> next){

        if(isPrime(get2NumDemical(k->data))){
            count ++;
        }
            
        
    }
    cout<<"\n So sau phan thap phan khong phai so nguyen to : "<<count;
}
int main(){
    list l;
    createList(l);
    enterList(l);
    printOutList(l);
    caculatePrime(l);
    isDemicalPrime(l);
}