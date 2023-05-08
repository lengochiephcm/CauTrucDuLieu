#include <iostream>
#define MAX 10000
using namespace std;

void input(int a[], int &n){
    cout<<"Nhap so phan tu cua mang: ";
    cin>>n;
    if(n < 1 ){

    while(n < 1){
       
        cout<<"Vui long nhap lai phan tu cua mang: ";
        cin>>n;
        
    }
    }
    
    cout<<"\n Thanh phan cua mang:  "; 
    for(int i = 0; i< n; i++){
      
        cout<<"\n a["<<i<<"]: ";
        cin>>a[i];
        cout<<endl;
    }
   
}
void output(int a[],int n){
    

    for(int i =0 ; i <n ; i ++){
        cout<<"\n a["<<i<<"]: "<<a[i];
    }
}
int insertsort(int a[], int n){
    int key, j;
    for(int i = 1; i <n ; i++){
        key  = a[i];
        j = i - 1 ;
        while(key < a[j]&& j >= 0){
            a[j+1]= a[j];
            j = j -1;
        }
        a[j + 1 ]= key;
    }
}
int main(){
    int n;
    int a[MAX];
    input(a,n);
    cout<<"\n Mang da nhap: ";
    output(a,n);
    insertsort(a, n);
    cout<<"\n Mang da sap xep: ";
    output(a,n);
}