//x,y, pass to wasp function x should become 20 y should become 30

#include<iostream>
using namespace std;


//ex-1
void swap(int *x, int *y) {
    int prevX= *x;
    *x= *y;
    *y=prevX;

};
//ex-2
struct Order{
    // int32_t orderId; -- check showing error
    int orderId;
};



int main() {
    int x=10;
    int y=20;

    cout << "Values before swap x : " << x << " -> y : " << y << endl;
    swap(&x, &y);
    cout << "Values after swap x : " << x << "-> y : " << y << endl;


    Order od1{1};
    Order* ptrO = &od1;
    cout << ptrO->orderId << endl;

}

