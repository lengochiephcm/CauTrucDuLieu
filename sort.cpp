#include<iostream>
using namespace std;

void input(int *&a, int &n){
    cout<<"\n Nhap gia tri cua mang: ";
    cin>>n;
    if (n< 1){
        while(n <1){
            cout<<"\n Vui long nhap lai gia tri cua mang lon hon 1: ";
            cin>>n;
        }
    }
    a = new int[n];
    cout<<"\n Nhap gia tri cua tung phan tu trong mang: ";
    cout<<endl;
    for(int i = 0 ; i < n; i++){
        cout<<"\n a["<<i+1<<"]: ";
        cin>>*(a+i);
    }
}
void output(int *a, int n){
    for(int i =0 ; i < n ;i++){
        cout<<"\na["<<i+1<<"]: "<<*(a+i);
    }
}
void bubble(int *a, int n){
    int temp;
    for(int i =0; i <n ;i++){
        for(int j = n -1; j > i; j --){
        if(*(a+j)  < *(a+j-1))
        {
            temp = *(a+j-1);
            *(a+j-1) = *(a+j);
            *(a+j) = temp;
        }
        }
    }
}
void interchange(int *a, int n){
    int temp;
    for(int i =0; i <n-1; i ++){
        for(int j =i+1; j < n; j++){
            if(*(a+i)>*(a+j))
            {
                temp = *(a+j);
                *(a+i)= *(a+j);
                *(a+j)= temp;
            }
        }
    }
}
void shakersort(int *a, int n){
    int left = 0;
    int right = n-1;
    int k = 0;
    while(left< right){
        for(int i = left;i <right; i++){
            if(*(a+i)>*(a+i+1)){
            swap(*(a+i),*(a+i+1));
            }
            k =i;
        }
        right = k;
        for(int i =right; i >left ; i--){
            if(*(a+i)<*(a+i-1)){
            swap(*(a+i),*(a+i-1));
            }
            k =i;
        }
        left = k;

    }
}
void selectionsort(int *a, int n){
    for(int i =0; i <n -1; i ++){
        int k =i;
        for(int j =i +1; j <n; j ++){
            if(*(a+k)>*(a+j)){
                 k =j;
                

            }
            swap(*(a+k),*(a+i));
        }
    }
}
void insertsort(int *a, int n){
    int key,j;
    for(int i =1 ; i <n ; i ++){
        int key = *(a+i);
        j = i -1;
        while(*(a+j )>key && j >=0){
            *(a+j+1) = *(a+j);
            j = j-1;
        }
        key = *(a+j+1);
    }
}
void merge(int *a, int m, int l, int r){
  int n1 = m +1;
  int n2 = r - m;
  int *left = new int [n1];
  int *right = new int [ n2];
  for( int i = 0; i < n1; i++){
    *(left + i) = *(a + l +i);
  } 
   for( int j = 0; j < n2; j++){
    *(right + j) = *(a + r + m +j);
  } 
  int k = 0;
  int i = 0;
  int j =0;
  while( i < n1 && j < n2){
    *(a + k ++) = (left[i] <= right[j] ? left[i++] : right[j++]);

  }
  while( i < n1){
    *(a+k ++) = left [i++];

  }
  while( j < n2){
    *(a+k++) = right [j ++];
  }
}
void mergesort(int *a, int l, int r){
    if (l <r){
        int m =  (r - l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1, r);
        merge(a,l,m ,r);
    }
}
void heapify ( int *a, int n , int i){
    int l = 2*i +1;
    int r = 2*i +2;
    int largest  = i;
    if ( l  < n && *(a+l) > *(a+ largest)){
        largest = l;
    }
    if ( r  < n && *(a+r) > *(a+ largest)){
        largest = r;
    }
    if ( largest != i){
        swap (*(a+i), *(a+ largest));
        heapify(a,n,largest);
    }

}
void heapsort( int *a, int n){
    for ( int i = n /2 -1; i >=0; i--){
        heapify(a,n,i);

    }
    for(int i = n -1 ; i >=0; i--){
        swap (*(a+i), *(a+0));
        heapify(a, i, 0);
    }
}
int main(void){
    int n ; 
    int *a;
    int l, r;
    input(a,n);
    cout<<"\n Gia tri ma vua nhap la: ";
    output(a,n);
    bubble(a,n);
    cout<<"\n Bubble sort: \n";
    output(a,n);
    interchange(a,n);
    cout<<"\n Interchange: ";
    output(a,n);
    shakersort(a,n);
    cout<<"\n Shaker Sort: ";
    output(a,n);
    selectionsort(a,n);
    cout<<"\n Selection sort: ";
    output(a,n);
    insertsort(a,n);
    cout<<"\n Insert sort: ";
    output(a,n);
    mergesort(a,l,r);
    cout<<"\n Merge sort: ";
    output(a,n);
    heapsort(a,n);
    cout<<"\n Heap sort: ";
    output(a,n);
    delete[]a;
    system("pause");
}