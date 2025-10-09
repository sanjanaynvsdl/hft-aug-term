#include<iostream>
#include<cstdint>
using namespace std;

struct String{
    char ptr[1024]; //if i change this to 1021 the order size still is 1036
    uint32_t size;
};


struct Order{
    String orderId; //1024+4 
    uint32_t qty;   //4 
    uint32_t price; //4
};

struct Order2{
    String *orderId; //pointer points to 8 
    uint32_t qty;    //4
    uint32_t price;  //4

};

int main() {
    cout << "Size of order strcut : " << sizeof(Order)<< endl; //1036
    cout << "size of order2 with astrick : " << sizeof(Order2) << endl;

    string a = "qewfefbqyfgqufyqdkjvnkdhfgiweuffasnjanahiwie";
    cout << sizeof(a) << endl; //32 but is it really 32?
    //like, who it's related to pointer, need to understand, 


}