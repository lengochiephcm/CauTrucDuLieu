#include <iostream>
#define MAX 1000
using namespace std;

void input(int a[], int &n){
    cout<<"Nhap so phan tu cua mang:  ";
    cin>>n;
    if(n<1){
        while(n<1){
            cout<<"\nVui long nhap lai so phan tu: ";
            cin>>n;
        }
    }
    cout<<"\n Nhap phan tu cua mnag: ";
    for(int i =0 ;  i < n; i++){
      cout<<"\na["<<i<<"]: ";
        cin>>a[i];
    }
}
void output(int a[],int n){
    

    for(int i =0 ; i <n ; i ++){
        cout<<"\n a["<<i<<"]: "<<a[i];
    }
}
int selection(int a[],int n){
    for(int i  =0 ; i < n-1 ; i++){
        int k = i;
        for(int j = i+1;j < n; j++){
            if(a[k]>a[j])
            k = j;
        }
        swap(a[k], a[i]);
    }
}
int main(){
    int n ;
    int a[MAX];
    input(a,n);
    cout<<"\n Mang da nhap: ";
    output(a,n);
    selection(a,n);
    cout<<"\n Mang sau khi sap xep: ";
    output(a,n);
    exit(0);
}