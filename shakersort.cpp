#include <iostream>
using namespace std;
void input(int a[], int &n)
{
    cout<<"Enter a size of array: ";
    cin>>n;
    cout<<"\nInsert a element of array: ";
    for( int i = 0 ; i < n ; i++)
    {
        
        cout<<"\na["<<i<<"]: ";
        cin>>a[i];
    }
}
void output( int a[], int n){
    cout<<"\nFull of array that you just enter: ";
    for( int i = 0 ; i < n ; i++){
        
        cout<<" a["<<i<<"]: "<<a[i];
    }
}

void arrayOfShaker(int a[], int n){
    int left = 0;
    int right = n -1;
    int k = 0;
    while ( left <right){
        for(int i = left; i < right ; i ++){
            if( a[ i]> a[i +1]){
                swap(a[i], a[i+1]);

            }
            k = i;
        }
        right = k;
        for ( int i = right ; i > left; i--){
            if ( a[i] < a[i-1]){
                swap(a[i], a[i-1]);

            }
            k =i;

        }
        left = k;
        }
}
void lastOutput(int a[], int n){
    cout<<"\nFull of array after sort:  ";
    for( int i = 0 ; i < n ; i++){
        
        cout<<" a["<<i<<"]: "<<a[i];
    }
}
int main ()
{
    int a[1000];
    int n ;
    input(a,n);
    output(a,n);
    arrayOfShaker(a,n);
    lastOutput(a,n);
    system("pause");
}