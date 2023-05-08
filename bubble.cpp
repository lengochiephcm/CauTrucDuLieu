#include <iostream>
#define MAX 1000
using namespace std;


void bubble(int a[],int n){
    for(int i  = 0 ; i < n  ; i ++ ){
        for( int j = n -1   ; j  > i ; j--){
        
        if(a[j ]< a[j -1])

        swap(a[j], a[j-1]);
    }
    }

    
}
void input(int a[], int &n){
    cout<<"Nhap phan tu mang: ";
    cin>>n;
    if( n <1 ){
        while(n <1 ){
            cout<<"\n Vui long nhap lai phan tu cua mang: ";
            cin>>n;
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        cout<<"\n a["<<i<<"]: ";
        cin>>a[i];
    }
}
void output(int a[], int n){
    cout<<"\n";
    for(int i =0 ; i < n; i ++){
        cout<<"\na["<<i<<"]: "<<a[i];
    }
}
int main()
{
    int n ;
    int a[MAX];
    input(a, n);
    output(a,n);
    bubble(a, n);
    cout<<"\n Mang sau khi sap xep: ";
    output(a,n);
}