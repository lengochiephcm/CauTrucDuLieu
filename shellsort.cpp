#include <iostream >
#define MAX 1000
using namespace std;

void input(int a[], int &n){
    cout<<"Nhap so phan tu cua mang : ";
    cin>>n;
    if( n< 1){
        while(n<1){
            cout<<"\n Vui long nhap lai so phan tu cua mang: ";
            cin>>n;
        }
    }
    cout<<"\n Nhap phan tu cua mang: ";
    for (int i =0 ; i < n ; i++){
        cout<<"\n a["<<i<<"]: ";
        cin>>a[i];
    }
}
void output(int a[], int n){
    for(int i =0 ; i< n ; i++){
        cout<<" \n a["<<i<<"]: "<<a[i];
    }
}
int shellsort(int a[], int n){
    for(int interval = n/2 ; interval > 0 ; interval /= 2){
        for(int i = interval ; i < n; i++){
            int j = i;
            int value = a[i];
        
        for(j = i; j >= interval && a[j - interval]> value; j -= interval){
            a[j ] = a[ j - interval];
        }
        a[j] = value;
    }
}
    
}
int main(){
    int n;
    int a[MAX];
    input(a,n);
    cout<<"\n Mang da nhap : ";
    output(a,n);
     shellsort(a,n);
    cout<<"\nMang da sap xep: ";
    output(a,n);

}