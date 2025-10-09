#include<iostream>
#include<cstdint>
using namespace std;

struct String{
    char ptr[1024]; //If I change this to 1021, the Order size is still 1036 (due to padding)
    uint32_t size;
};


struct Order{
    String orderId; //1024+4
    uint32_t qty;   //4
    uint32_t price; //4
};

struct Order2{
    String *orderId; //Pointer takes 8 bytes
    uint32_t qty;    //4
    uint32_t price;  //4
};

int main() {
    cout << "Size of order strcut : " << sizeof(Order)<< endl; //1036
    cout << "size of order2 with astrick : " << sizeof(Order2) << endl;

    string a = "qewfefbqyfgqufyqdkjvnkdhfgiweuffasnjanahiwie";
    cout << sizeof(a) << endl; //32, // 32 (object size)


    /*
        What	                Size
        sizeof(string)	        32 bytes (always!)
        String content	Variable (depends on text)

        a.size()	            45 (for your string)

        The 32 bytes is just the "container" - the actual text is stored elsewhere!*/


}