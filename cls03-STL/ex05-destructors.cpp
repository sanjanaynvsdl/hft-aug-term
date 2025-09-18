#include<iostream>
using namespace std;


//Whenever we create obj using new
//- 1. it's dynamic memory
//-2. in heap memoey
struct Student{
    int marks;
    string name;

    Student(int m, string n) {
        marks=m;
        name=n;
    }

    //this is destructor, when i create a instance of thisstruct,
    //the destructor is being called, 
    ~Student() {
        cout << name << " is getting deleted";
    }
};

void fn() {
    //this doesnt' call the destructor
    //cpp has doen't have a way to clear heap memory-> using new this is being storred, in heap memory
    Student *st1 = new Student(100, "hello");
    Student *st2 = new Student(200, "hi");


    //this calls destructor -> this is the stack memory
    // Student s1{100,"sanjana"};
    // Student s2{200, "ynvsdl"};
}


int* fun() {
    int n=2;
    int arr[n]={1,2};
    return arr;
}


//dynamic arr, -> so this will work and store, 
int* inputFn(int n) {
    int arr[n]={12,13,15};

    return arr;
};

int main() {
    fn();

    // int* arr = fun();
    // cout << arr[0] << endl;
    //since this variables are local -> 
    // warning: address of local variable 'arr' returned,


    int size;
    // cin >> size;
    // int* arr = inputFn(size); //even here i would get the, issue compiler issue
    //if compiler is not there, there would be a dynamic allocation allocated to it, 
    // cout << arr[0];


    //Q- write a java code, to 
    //which creates a rray of 1mb size 
    //and 1million of those, 


    


}