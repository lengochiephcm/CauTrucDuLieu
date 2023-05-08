#include <iostream>
using namespace std;

void inputArray( int a[], int &n)

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
void bubblesort(int a[], int n)
{
    for( int i = 0 ; i < n ; i++)
    {
        for ( int j = n -1 ; j >i ; j--)
        if(a[j]< a[j -1 ])
        swap(a[j ] , a[j-1]);
    }
}
void shakersort( int a[], int n)
{
    int left = 0;
    int right = n -1 ;
    int k =0;
    while ( left < right){
    for ( int i = left ; i <right ; i++)
    {
        if ( a[i]> a[i+1 ])
        {
            swap(a[i], a[i+1]);
            k = i;
        }
    }
    right = k;
    for ( int i = right ; i > left ; i--)
    {
        if (a[i] < a[i-1])
        {
            swap(a[i], a[i-1]);
            k = i;
        }
    }
    left = k;
    }
}
void output(int a[], int n){
    for(int i = 0 ; i< n ; i++)
    {
        cout<<" a["<<i<<"]: "<<a[i];
    }
    cout<<"\n";
}
int main()
{
    int a[5000];
    int n;
    inputArray(a, n);
    bubblesort(a,n);
    output(a,n);
    shakersort(a,n);
    output(a,n);
    system("pause");
    
}