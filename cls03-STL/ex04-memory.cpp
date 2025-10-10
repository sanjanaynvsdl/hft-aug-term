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
    // Memory of a program
    /* There are two types of memory: stack memory and heap memory
    The memory which we can see and know during compilation is stack memory
    - Understanding stack frames with example
    */

   // This we can say around 8 bytes
    int x=2;
    int z=2;

    // But this memory we will get to know at run-time
    int arrLen;
    cin >> arrLen;
    int arr[arrLen];

    int y=8; 
    int* ptrY = &y;
    fn(ptrY);
    cout << y << endl;



    /*
    1. In RAM we have y=8
    2. In RAM we again store address of y in ptrY
    3. Call fn and pass ptrY
    4. When we pass to fn, it's again pass by value
    5. Creates another ptrY which points to Y
    6. We are making this ptrY point to null

    In main function output we saw the output as 8, because ptrY points to null not y
    */


    int* value  = f();
    // cout << "pointer address is : " x;
    // cout << "value of is : " << *value;
    /*
    - In the stack frame, first main goes then f()
    - In f declares x, returns address since it's done, f() will completely vanish from memory
    - Now we only have a null ptr
    - Warning: "address of local variable 'x' returned"
    */


    //------------------------------------------
    // In C++ we do not have garbage collector but destructor

}