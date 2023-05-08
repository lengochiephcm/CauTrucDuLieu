#include <iostream>
#include <fstream>
using namespace std;
typedef struct node{
    int data;
    node*left;
    node *right;

}node;
typedef struct node *tree;
void createTree(tree &t){
    t = NULL;

}
void addNewNode(tree &t,int x){
    if(t == NULL){
        node *p = new node;
        p->data =x;
        p->right = NULL;
        p->left = NULL;
    }
    else{
        if( t -> data > x){
            addNewNode( t ->left , x);
        }
        else if(t-> data < x){
            addNewNode(t->right,x);
        }
    }
}
void NLR(tree t){
    if(t){
        cout<<t->data<<" ";
        NLR(t->left);
        NLR(t->right);
    }
}
void LNR(tree t)
{
    if(t){
        LNR(t->left);
        cout<<t->data<<" ";
        LNR(t->right);
    }
}
void LRN(tree t){
    if(t){
        LRN(t->left);
        LRN(t->right);
        cout<<t->data<<" ";

    }
}
void countLeaf(tree t){
    int count = 0;
    if(t){
        if(t->left == NULL && t->right == NULL){
            count++;

        }
        countLeaf(t->left);
        countLeaf(t->right);
    }
}
void countNode1Subtree(tree t){
    int count = 0;
    if(t){
        if((t->left != NULL && t->right == NULL) || (t->left == NULL && t->right != NULL))
        {
            count++;
        }
        countNode1Subtree(t->left);
        countNode1Subtree(t->right);
    }
}
void countNode2Subtree(tree t){
    int count = 0;
    if(t){
        if(t->left != NULL && t->right != NULL){
            count++;
        }
        countNode2Subtree(t->left);
        countNode2Subtree(t->right);
    }
}
void findALargestNode(tree t){
    if(t){
        findALargestNode(t->right);
        
    }
    else{
        cout<< t-> data<< " ";
    }
}
void readFile(tree &t, ifstream &filein){
    int n ;
    filein >>n;
    for(int i  = 1;i<= n ; i++){
        int x;
        filein >>x;
        addNewNode(t,x);
    }

}
void readFile2(tree&t, ifstream&filein){
    
    while(true){
        int x;
        filein>>x ;
        addNewNode(t,x);
        char c;
        filein>>c;
        if(filein.eof()== true)
        {
            break;
        }
    }
}

int main(){
    tree t;
    createTree(t);
    ifstream filein;
    // filein.open("input.txt",ios_base::in);
    // readFile(t,filein);
    // cout<<"\n Print out of Tree: ";
    // NLR(t);
    // filein.close();
    // filein.open("input.txt",ios_base::in);
    // readFile2(t,filein);
    // cout<<"\n Print out of Tree: ";
    // NLR(t);
    // filein.close();

    delete t;

}