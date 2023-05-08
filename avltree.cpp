#include <iostream >
#define LH -1
#define EH 0
#define RH 1
using namespace std;
typedef struct node{
    int key;
    char balFactor;
    struct node* left;
    struct node* right;
}nodeAVL;
typedef nodeAVL *avl;
void createTree(avl&t){
    t== NULL;

}
void addNewNode(avl&t, int x){
    if(t== NULL){
        nodeAVL *p = new nodeAVL;
        p->key = x;
        p->left = NULL;
        p->right = NULL;
        t = p;
    }
    else if(t ->key > x){
        addNewNode( t->left ,x);
    }
    else if(t->key < x){
        addNewNode(t->right, x);
    }
}
void nodeLeftRight(avl t){
    if(t){
        cout<<"\n ";
        cout<<t->key<<" ";
        nodeLeftRight(t->left);
        nodeLeftRight(t->right);
    }
}
void rotateRR(avl &t){
    nodeAVL *t1 = t->right;
    t->right = t1->left;
    t1->left =t;
    switch(t1->balFactor){
        case RH :
        t->balFactor = EH;
        t1->balFactor = EH;
        break;
        case EH:
        t->balFactor = RH;
        t1->balFactor = LH;
        break;
    }
    t =t1;
}
void rotateLL(avl &t){
    nodeAVL *t1 = t ->left;
    t->left = t1 ->right;
    t1->right =t;
    switch(t1->balFactor){
        case LH : 
        t->balFactor = EH;
        t1->balFactor = EH;
        break;
        case EH: 
        t->balFactor = LH;
        t1->balFactor = EH;
        break;
    }
    t =t1;
}
void rotateLR(avl &t){
    nodeAVL*t1 = t->left;
    nodeAVL*t2 = t1->right;
    t->left = t2->right;
    t2->right = t;
    t1->right = t2->left;
    t2->left = t1;
    switch(t2->balFactor){
        case LH:
        t->balFactor= RH;
        t1->balFactor= EH;
        break;
        case EH: 
        t->balFactor = EH;
        t1->balFactor = EH;
        break;
        case RH:
        t->balFactor = EH;
        t1->balFactor = LH;
        break;
    }
    t2->balFactor = EH;
    t=t2;
}
void rotateRL(avl&t){
    nodeAVL*t1 = t->right;
    nodeAVL*t2= t1->left;
    t->right = t2->left;
    t2->left =t;
    t1->left = t2->right;
    t2->right = t1;
    switch(t2->balFactor){
        case EH:
        t1->balFactor = EH;
        t->balFactor = EH;
        break;
        case LH: 
        t->balFactor = EH;
        t1->balFactor = RH;
        break;
        case RH:
        t->balFactor = LH;
        t1->balFactor = EH;
        break;
    }
    t2->balFactor= EH;
    t= t2;
}
int balanceLeft(avl&t){
    nodeAVL* t1=t->left;
    switch(t1->balFactor){
        case LH: 
        rotateLL(t);
        return 2;
        case EH: 
        rotateLL(t);
        return 1;
        case RH: 
        rotateLR(t);
        return 2;

    }
    return 0;
}
int  balanceRight(avl&t){
    nodeAVL*t1 = t->right;
    switch(t1->balFactor){
        case LH: 
        rotateRR(t);
        return 2;
        case EH: 
        rotateRR(t);
        return 1;
        case RH:
        rotateRL(t);
        return 2;

    }
    return 0;
}
