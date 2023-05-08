#include <iostream>
#include <fstream>
using namespace std;

FILE*fp;
int main(){
    int n, tmp;
    int *arr;
    fp = fopen("C:\\Users\\COMPUTER\\OneDrive\\Desktop\\chohiep.txt","rt");
    if(!fp){
        cout<<"\nCouldn't open ";
        exit(0);
    }
    fscanf(fp,"%d",&n);
    if(n < 1 ){
        cout<<"\nERROR: COULDN'T READ";
        fclose(fp);
        exit(0);
    }
    cout<<"\n n = "<<n;
    arr= new int[n];
    if(!arr){
        cout<<"\n ERROR : COULDN'T READ";
        exit(0);
    }
    for(int i =0 ; i < n ;){
        fscanf(fp, "%d",&tmp);
        arr[i++]= tmp;
    }
    cout<<endl;
    
    for(int i  =0 ; i< n; i++){
        
        cout<<arr[i]<<" ";
    }
    fclose(fp);
    delete[] arr;
    exit(0);
}