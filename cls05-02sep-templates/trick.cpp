#include<iostream>
#include<cstdint>
using namespace std;

struct X{
    uint32_t x;  //size-> 32/8 -> 4 bytes
    uint32_t y;  //y-size -> 4 bytes
    char z;      // char -> 1 byte
    //total size of X is 9bytes, this is what out thoughts when we see this, 
};

struct Trick2{
    char x;
    uint32_t y;
};

/*
0 1 2 3 4 5 6 7 8 -> 
a b b b b 
this is how we think if its 5 bytes the b should start a such a address tha's readable


0 1 2 3 4 5 6 7 8 
a       b b b b 
starts at 4 rest are left as padding by cpp,
this is why cpp added padding, to align addresses properly

Padding -> 
Alignment -> evey data type should stay on multiple of it's own, like here it's 4


*/


//alignment of a struct  which address it should start
//in this case we want to know the maxm alignment of struct in this case its y, -> 4
struct Trick3{
    char x;
    uint32_t y;
    char z; //as i add x, now size is 12
};

/*
now, the size is 12, becasue when i add Trick3 in an array second time, 

0 1 2 3 4 5 6 7 8   [Trick 3 can start at 9 as x=1 byte but not y ]   9 10 11 12
x _ _ _ y y y y z -> sir told that x can start y but not y im a bit confused we can leave as pasddidng and start from 12 right, 
- it's becuase we need/ array is a continuous memory,

*/
int main() {
    cout<< "Size is of X : " << sizeof(X) << endl; //print 12 why?
    //this was supposed to print 9, but it did 12
    //so in cpu we have word size -> protocol in cpu
    //to read 4bytes we cant' start a -- wihtou a multiple of 4,
    //this is how os, and hardware is


    ///questions were on, stacks heaps, padding mis alignment
    //nd why it's important for the performance
    //assume i have array of size 2 of stuct  X[2];

    /*

    0 1 2 3 4 5 6 7 8 9 2-> 10 11 12 13 14 15 16 17 18 19
    x x x x y y y y y z 2->  x  x  x  x  y  y  y  y  z
    x x x x y y y y z              x  x  x  x  y  y  y 
    in this case read of sedoncs x cannot happen why?
    this is why it takes extra 3bytes
    the architecture are like i will only pick address that are multiple of 4
    but some architectures allow,
    */

    cout << "Size of trick2 is : " << sizeof(Trick2) << endl;
    //supposed to be 5 but reutnrs 8-> multiple of 4


    //-----we have done this excercie to understand the before padding issue with the memorypool problem, 
    
    
}
