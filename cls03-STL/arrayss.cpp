#include<iostream>
using namespace std;

struct Order{
    int orderId;
    int qty;
    int price;
};

int totalQuantity(Order newOrders[], int N) {
    int sum =0;
    for(int i=0;i<N;i++) {
        sum+= newOrders[i].qty;
    }

    return sum;
};

void maxAtFirst(int arr[4]) {
    swap(arr[0],arr[2]);  
    
    // arr[0] works but why not size?
    // Because arr[0] internally points to the address + 0 (*arr+0)
    //  for(int i=0;i<sizeof(arr)/sizeof(int);i++) {
    //     cout << arr[i] << " ";
    // }
    // This throws the warning:
    // warning: 'sizeof' on array function parameter 'arr'
    // will return size of 'int*' [-Wsizeof-array-argument]

    // For arrays, it's by default a pointer, we can see the asterisk (*) in the warning message
};

int main() {
    int arr[4]={4,5,6,8};
    char charArr[4]={'a','b','c','d'};

    Order arrOrder[4];
    int max=arr[0];

    //Q1- write code to find the maximum value in the array
    for(int i=0;i<3;i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    cout << "Maximum value is " << max << endl;

    // Q2 - Write a function to find the maximum and place at the beginning of array
    int arr2[5]={2,5,10,0};
    maxAtFirst(arr2);
    int arrSize = sizeof(arr2)/sizeof(int);
    cout << "final array after replacing!" << endl;
    for(int i=0;i<arrSize;i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;


    // Output: {10 5 2 0 0}
    // C++ is pass by value, so why did this array change?
    // C++ arrays have a default behavior of decaying to a pointer


    // arr  [4,5,6,8]
    cout << "arr address : " << arr << endl; // 0x7c283ff960
    // Prints pointer to first number in arr
    cout << "first num : "  << *arr << endl; // 4

    // Now print the 2nd
    cout << "2nd num in arr " << *arr + 2 << endl;



    // Q3 - Make an array of structs with orders
    // Order has price and quantity
    // Calculate the total quantity from a function 
    Order newOrders[4] = {{1,2,30},{2,6,100},{3,4,200},{4,6,500}};
    int totalQty = totalQuantity(newOrders,4);
    cout << "total qty of order are : " << totalQty << endl;
    


     


 

}