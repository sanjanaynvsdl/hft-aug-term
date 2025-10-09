#include<iostream>
using namespace std;

template <typename XYZ>


void Print(XYZ value) {
    cout << value << endl;

}

int main() {

    Print<int>(5);
    Print<double>(4.5);

}

//if we do not use this pritn func in main, it wont' be created, beacues we are creating in the run time, 
//based on the usage of template it creates, 
//we can use the templates with the classes too, x