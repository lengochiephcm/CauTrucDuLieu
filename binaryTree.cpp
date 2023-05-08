#include <iostream>
using namespace std;
typedef struct nodeTree {
    int data ;
    node *left;
    node *right;
}node;
typedef node *tree;
void createTree(tree &t){
    t = NULL;
}
void addNewNode(tree &t, int x){
    if(t == NULL){
        node *p = new node;
        p-> data = x;
        p-> right = NULL;
        p-> left = NULL;
        t =p ;
    }
    else {
        if(t -> data > x){
            addNewNode(t->left, x );
        }
        else if(t-> data < x){
            addNewNode(t->right, x);
        }
    }
}
void nodeLeftRight(tree t){
    if(t!= NULL){
        cout<<t-> data<<" ";
        nodeLeftRight(t-> left);
        nodeLeftRight(t-> right);

    }
}
void leftRightNode(tree t){
    if(t){
        leftRightNode(t->left);
        leftRightNode(t->right);
        cout<<t->data <<" ";
    }
}
void leftNodeRight(tree t){
    if(t){
        leftNodeRight(t->left);
        cout<<t->data<<" ";
        leftNodeRight(t->right);

    }
}
int countLeaf(tree t){
    int count = 0;
    if(t){
        if(t-> left == NULL && t-> right == NULL){
        count++;
        }
        countLeaf(t->left );
        countLeaf(t->right);
    }
    return count;
}   

// void print2DUtil(node root, int space){
//     if(!root){
//         return;

//     }
//     space += 10;
//     print2DUtil(root->right, space){
//         cout<<endl;
//     }
//     for(int i = 10; i <space;i++){
//         cout<<" ";
//         cout<<root-> data<<"\n";
//         print2DUtil(root->left,space);
//     }
// }
// void print2D(node root){
//     print2DUtil(root,0);
// }
// void printTree(tree t){
//     print2D(t.root);
// }


void menu(tree &t){
    while(true)
{
    cout<<"\n\t====== MENU ======\t\n";
    cout<<"\n 1. Nhap cay nhi phan. ";
    cout<<"\n 2. Xuat cay nhi phan NRL. ";
    cout<<"\n 3. Xuat cay nhi phan LRN. ";
    cout<<"\n 4. Xuat cay nhi phan LNR. ";
    cout<<"\n 5. So node la trong cay nhi phan. ";
    cout<<"\n 6. Thoat chuong trinh.";
    int n;
    cout<<"\n Nhap lua chon: ";
    cin>>n;
    if(n < 1 || n > 6){
        cout<<"\n Lua chon khong lop le.";
        cout<<"\n Vui long nhap lai: ";
        cin>>n;
        system("pause");
    }
    else if(n == 1 ){
        int x;
        cout<<"\n Nhap so nguyen x: ";
        cin>>x;
        addNewNode(t,x);
    }
    else if( n == 2 ){
        nodeLeftRight(t);
        system("pause");
    }
    else if(n == 3){
        leftRightNode(t);
        system("pause");
    }
    else if( n == 4){
        leftNodeRight(t);
        system("pause");
    }
    else if(n ==5 )
    {
        countLeaf(t);
        system("pause");
    }
    else 
    break;

}
}


int main()
{
    tree t;
    createTree(t);
    // addNewNode(t);
    // leftNodeRight(t);
    // countLeaf(t);
    menu(t);
}