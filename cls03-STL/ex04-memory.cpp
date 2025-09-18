#include<iostream>
using namespace std;

void fn(int* y) {
    y=nullptr;


};

int* f() {
    int x=2;
    return &x;
}

int main() {
    //memory of a program
    /* there are two types of memory stack memory and heap memory
    the memory which we can see andknow durin gcompilation could be a stack memory,
    - understanding stack frames with example
    */

   //this we can say aorund 8bytes
    int x=2;
    int z=2;

    // but, this memeoy we will get to know on run-time
    int arrLen;
    cin >> arrLen;
    int arr[arrLen];

    int y=8; 
    int* ptrY = &y;
    fn(ptrY);
    cout << y << endl;



    /*
    1. in RAM we have y=8
    2. in RAm we agsint store address of y in ptrY
    3. call fn pass ptrY
    4. now, when we passed to fn, it's agins pass by value, 
    5. creates anotehr ptrY whic points to Y;
    6. and we are making this ptrY to point null;
    
    on mian fucniton ouput we saw the output as 8, becasue ptrY points to null not y
    */


    int* value  = f();
    // cout << "pointer address is : " x;
    // cout << "value of is : " << *value; 
    /*
    - in the stack frame, first main goes then f()
    - in f declares x, returs address since it's done, f() will completely vanish from memory
    - now we only have a null ptr, 
    - so warning " warning: address of local variable 'x' returned "
    */


    //------------------------------------------
    // in cpp we do not have garbage colletor but destructor

}