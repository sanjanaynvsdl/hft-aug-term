#include<iostream>
using namespace std;


//write a power function using template
template<int A, int B>
struct Power{
    constexpr static int result = A*Power<A,B-1>::result;
};

template<int A>
struct Power<A,0>{
    constexpr static int result = 1;
};

//do not worry about the optimized version while writting templates


int power(int x, int y) {
    //2^12 
    //2^6
    //2^3
    //2^1

    //divide
    if(y==0) return 1;
    int temp=power(x,y/2);

    if(!(y&1)) {
        //division alone is 20 cpu cycles, instead of (y%2) use bitwise
        return temp*temp;
    } else {
        return temp*temp*x;
    }
}

int main() {
    cout << Power<2,4>::result << endl;
    cout << power(2,4) << endl;

}