#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;

} node;
typedef struct linkedlist{
    node *head;
    node *tail;
}list;
int createLinked(list &l){
    l.head = l.tail = NULL;
   
}
int isEmpty(list l){
    return (l.head == NULL);
}
node *createNode(int n){
    node *p = new node;
    if (p == NULL){
        cout<<" Khong du bo nho de khoi tao danh sach ";
    }
    p->data = n;
    p-> next = NULL;
    return p;

}
void addFisrtposition(list &l, node *p){
    if(isEmpty(l)){
        l.head = l.tail = p;

    }
    else{
        p -> next = l.head;
        l.head = p;

    }
}
void addLastPosition(list &l, node *p){
     if(isEmpty(l)){
        l.head = l.tail = p;

    }
    else{
        l.tail -> next = p;
        l.tail = p;



    }
}
void inputLinkedlist(int &n, int &x, list &l){
    
    cout<<"\n Nhap so luong cua danh sach lien ket: ";
    cin >>n;
    for(int i =0 ; i <n ; i++)
    {
        int x;
        cout<<"\n Nhap gia tri " <<i+1<<" : ";
        cin>>x;
        node *p =createNode(x);
        addLastPosition(l,p);
        
    }
}
void printOutLinkedlist(list l){
    for(node *k = l.head; k!= NULL ;k = k -> next){
        cout<< k->data<<" ";

    }
}
void addFirst( list &l, int &f){
    cout<<"\n Nhap gia tri them vao truoc mang: ";
    cin>>f;
    node *q = createNode(f);
    addFisrtposition(l,q);
    
    
}
void addLast(list &l, int &a){
    cout<<"\n Nhap gia tri can them vao sau mang: ";
    cin>>a;
    node *q = createNode(a);
    addLastPosition(l,q);
}
void addRandomBehind(list &l, int k, int x){
    cout<<"\n Nhap gia tri can them vao danh sach: ";
    cin>>k;
    cout<<"\n Nhap gia tri can them vao sau: ";
    cin>>x;
    node *p = createNode(k);
    node*q = createNode(x);
    if( q -> data == l.head -> data){
        addLastPosition(l,p);
    }
    else{
        for(node *z = l.head ; z != NULL; z = z-> next){
            if( q -> data == z -> data){
                node *g = z -> next;
                p -> next = g;
                z -> next = p;
            }
        }
    }
}
void addRandomFront(list &l, int k, int x){
    cout<<"\n Nhap gia tri can them vao mang: ";
    cin>>k;
    cout<<"\n Nhap gia tri can them vao truoc: ";
    cin>>x;
    node *p = createNode(k);
    node*q = createNode(x);
    if( q -> data == l.head -> data){
        addFisrtposition(l,p);
    }
    else{
        node *g = new node;
        for(node *z = l.head ; z != NULL; z = z-> next){
            if( q -> data == z -> data){
                p -> next = z;
                g -> next = p ;

            }
            g=z;
        }
    }

}
void addRandomPosition(list &l, int k){
    cout<<"\n Nhap gia tri can them vao mang : ";
    cin>>k;
    int pos =0, n;
    node *p = createNode(k);
    for( node *k = l.head; k!= NULL ; k = k-> next){
        pos++;

    }
    do{
    cout<<"\n Nhap vi tri can them vao trong mang:  ";
    cin >>n;
    if ( n < 1 || n > pos + 1){
        cout <<"\n Vui long nhap lai gia tri them vao truoc nam trong khoang [1 ;"<<pos<<"] ";
    }
    }while( n < 1 || n > pos + 1);
    if ( isEmpty(l)){
        addFisrtposition(l,p);
    }
    else if( n == pos +1 ){
        addLastPosition(l,p);
    }
    else {
        node *g = new node;
        int count =0;

        for(node *k = l.head  ; k != NULL ; k = k-> next){
            count ++;
            
        if ( count == n ){
            p-> next = k;
            g-> next = p;
        }
        g = k;
        }
    }

    

}
void deleteFirstPosition(list &l){
    if(isEmpty(l)){
        return;

    }
    node *p = l.head ;
    l.head = l.head -> next;
    delete p;
}
void deleteLastPosition(list &l){
    if(isEmpty(l)){
        return ;

    }
    for(node * k = l.head ; k != NULL ; k = k -> next){
        if( k -> next == l.tail){
            delete l.tail;
            k -> next =NULL;
            l.tail = k;
            return;
        }
    }

}
void deleteBehind(list &l){
    int k;
    cout<<"\n Nhap gia tri trong danh sach can xoa phia sau: ";
    cin>>k;
    node *p = createNode(k);
    for(node *k = l.tail ; k != NULL; k =k -> next){
        if( k -> data == p -> data){
            node* g= k -> next;
            k-> next = g->next;
            delete g;
            return;
        }
    }
}
void deleteFront(list &l){
    int x;
    cout<<"\n Nhap gia tri trong danh sach can xoa phia truoc: ";
    cin>>x;
    node *p = createNode(x);
    for(node *k = l.head ; k != NULL ; k =k -> next){
        node *g = new node;
        if(k -> data == p -> data){
            node *j = new node ;
            g -> next = k;
            g = j-> next;
            j -> next = p;
            delete g;
            return;
        }
        g = k;
        


        
    }
}
void deleteRandomPosition(list &l){
    int k;
    cout<<"\n Nhap gia tri can xoa trong danh sach: ";
    cin >>k;
    node *p = createNode(k);
    if(isEmpty(l))
    return;
    if(l.head -> data == k){
        deleteFirstPosition(l);
    }
    else if(l.tail-> data == k)
{
    deleteLastPosition(l);

}    
    node *g= new node;
    for( node *k = l.head ; k!= NULL; k = k -> next){
        if ( k -> data == p-> data){
            g-> next = k -> next;
            delete k;
            return;

        }    
        g = k;

    }
}
void releaseMemories(list &l){
    for(node *k = l.head ; k != NULL ; k = k-> next){
        delete k;

    }
}
int main(){
    list l;
    
    createLinked(l);
    int n,x;
    inputLinkedlist(n,x,l);
    cout<<"\n Danh sach da nhap: ";
    printOutLinkedlist(l);
    // int f;
    // addFirst(l,f);
    // printOutLinkedlist(l);
    // int a,k;
    // addLast(l,a);
    // printOutLinkedlist(l);
    // addRandomBehind(l,k,x);
    // printOutLinkedlist(l);
    // addRandomFront(l,k,x);
    // printOutLinkedlist(l);
    // addRandomPosition(l,k);
    // printOutLinkedlist(l);
    // deleteFirstPosition(l);
    // cout<<"\n Danh sach sau khi xoa phan tu dau: ";
    // deleteLastPosition(l);
    // cout<<"\n Danh sach sau khi xoa phan tu cuoi: ";
    // printOutLinkedlist(l);
    deleteFront(l);
    cout<<"\n Danh sach xoa truoc: ";
    printOutLinkedlist(l);
    // deleteRandomPosition(l);
    // cout<<"\n Danh sach sau khi xoa vi tri random: ";
    //printOutLinkedlist(l);
    system("pause");
    releaseMemories(l);
    
    return 0;
}