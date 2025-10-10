#include<iostream>
using namespace std;


// Whenever we create obj using new:
// 1. It's dynamic memory
// 2. In heap memory
struct Student{
    int marks;
    string name;

    Student(int m, string n) {
        marks=m;
        name=n;
    }

    // This is destructor, when I create an instance of this struct,
    // the destructor is being called 
    ~Student() {
        cout << name << " is getting deleted";
    }
};

void fn() {
    // This doesn't call the destructor
    // C++ doesn't have a way to clear heap memory -> using new stores it in heap memory
    Student *st1 = new Student(100, "hello");
    Student *st2 = new Student(200, "hi");


    // This calls destructor -> this is stack memory
    // Student s1{100,"sanjana"};
    // Student s2{200, "ynvsdl"};
}


int* fun() {
    int n=2;
    int arr[n]={1,2};
    return arr;
}


// Dynamic array - this will work and store
int* inputFn(int n) {
    int arr[n]={12,13,15};

    return arr;
};

int main() {
    fn();

    // int* arr = fun();
    // cout << arr[0] << endl;
    // Since these variables are local:
    // warning: address of local variable 'arr' returned


    int size;
    // cin >> size;
    // int* arr = inputFn(size); // Even here I would get the compiler issue
    // If compiler is not there, there would be dynamic allocation
    // cout << arr[0];


    // Q - Write a Java code which creates an array of 1MB size and 1 million of those 


    


}