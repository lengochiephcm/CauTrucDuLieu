#include <iostream>
using namespace std;

class Complex{
    private : 
    int real, imaginary;
    public :
        void createComplex()
        {
            cout<<"\nEnter a real number:  ";
            cin>>real;
            cout<<"\nEnter a imaginary number: ";
            cin>>imaginary;

        } 
        void output()
        {
            cout<<"\nEquation : "<<real<<"+ "<<imaginary<<"i";
        }
        int getReal(){
        return real;
        }
        int getImainary(){
        return imaginary;
        }


};
int main()
{
    Complex a[2];
    
    for( int i =0 ; i < 2 ; i++)
    {
        a[i].createComplex();
    }
    cout<<"\nAddition of 2 complexes: "<<a[0].getReal() + a[1].getReal()<<" + "<<a[0].getImainary()+a[1].getImainary()<<"i";
}