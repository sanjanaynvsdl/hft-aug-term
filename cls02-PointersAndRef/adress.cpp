#include<iostream>
using namespace std;

int main() {
    // int x = 10;
    // // int y= &x; 
    // //this is not correct but there won't be differentiator in the way we stor

    // int* y=&x; //(astric y)

    int x=10;
    int* ptrX= &x;

    cout <<"X value is : " << x << endl;
    cout <<"address of X is : " << ptrX << endl;
    cout <<"what does this print? : " << *ptrX <<endl; //goes a step beyond, gets value of X,

    //char -> a corner case we'll understand later,
    char a = 'b';
    char* ptrA = &a;
    cout <<"value of a is " << a << endl;
    std::cout << "address of char is " << ptrA << endl;
    std::cout << "value from address -> " << *ptrA << endl;


    //double
    double num = 34.5;
    double* prtNum = &num;
    cout << "double ex -> " << num << " address -> " << prtNum << endl;
    cout << "value is -> " << *prtNum << endl;


 
}