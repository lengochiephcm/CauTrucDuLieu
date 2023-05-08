
#include <iostream>
#include <fstream>
using namespace std;
FILE*fp;
int main()
{
    int n,tmp;
    int *arr;
    fp=fopen("C:\\Users\\COMPUTER\\OneDrive\\Desktop\\chohiep.txt","rt");
    if(!fp)
    {
        cout<<"Error: Couldn't open";
        exit(0);
    }
    fscanf(fp,"%d",&n);
        if(n<1)
    {
        cout<<"Error: Couldn't";
        fclose(fp);
        exit(0);
    }
    cout<<"n= "<<n<<endl;
    arr= new int[n];
    if(!arr) 
    {
        cout<<"Error: Couldn't";
        exit(0);
    }
    for(int i=0; i<n;)
    {
        fscanf(fp,"%d",&tmp);
        arr[i++]=tmp;
    }



    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    fclose(fp);
    delete[] arr;
    return 0;
}
 