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
    
    // arr[0] -> works but why not size
    //coz, arr[0] internally points to the aress + 0 mean (*arr+0)
    //  for(int i=0;i<sizeof(arr)/sizeof(int);i++) {
    //     cout << arr[i] << " ";
    // }    
    //this throws the warning ->
    // warning: 'sizeof' on array function parameter 'arr' 
    //will return size of 'int*' [-Wsizeof-array-argument]

    //so for arrays, it's by default the pointer, we can see the * astrick above in the warning message
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

    //q2-  write a function to find the maximum and place at the begining of array,
    int arr2[5]={2,5,10,0};
    maxAtFirst(arr2);
    int arrSize = sizeof(arr2)/sizeof(int);
    cout << "final array after replacing!" << endl;
    for(int i=0;i<arrSize;i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;


    //output - {10 5 2 0 0}
    //cpp is an pass by value then why did this array change, why did this array shared the ref,
    //cpp for arrays -> have an default behaviour of declaring to a pointer


    //arr  [4,5,6,8]
    cout << "arr address : " << arr << endl; //0x7c283ff960
    //prints pointer to first number in arr
    cout << "first num : "  << *arr << endl; //4

    //now print the 2nd
    cout << "2nd num in arr " << *arr + 2 << endl;



    //Q3- make an array of strcuts, with orders, 
    //order has -> price, quantity, 
    //now, calulate the total quantity from a function, 
    Order newOrders[4] = {{1,2,30},{2,6,100},{3,4,200},{4,6,500}};
    int totalQty = totalQuantity(newOrders,4);
    cout << "total qty of order are : " << totalQty << endl;
    


     


 

}