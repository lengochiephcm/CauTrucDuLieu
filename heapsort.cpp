#include <iostream>
using namespace std;
#define MAX 1000

int input(int a[],int &n){
    cout<<"Nhap so phan tu mang: ";
    cin>>n;
    if(n < 1){
        while(n<1){
            cout<<"\n Vui long nhap lai so phan tu: ";
            cin>>n;

        }
    }
    cout<<"\n Nhap phan tu mang: ";
    cout<<endl;
    for(int i = 0 ; i< n; i ++){
        cout<<"\na["<<i<<"]: ";
        cin>>a[i];
    }
}
int output(int a[], int n){
    for(int i  =0 ; i < n; i++){
        cout<<"\na["<<i<<"]: "<<a[i];
    }
}
int createHeap(int a[], int n){
    for(int k = (n+1)/2 -1 ; k >= 0; k++){
        insetHeap(a,k,n-1);
    }
}
int insertHeap(int a[], int l, int r){
    int p = 2*l;
    if(p>r)
    return 0;
    if( p < r)
    {
        if(a[p]> a[p+1])
        p = p+1;
    }
    
}