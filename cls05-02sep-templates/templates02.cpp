#include<iostream>
#include<cstdint>
using namespace std;


//Q: Create SST, SSB student and write a function to accept these objects and return the sum of their marks
//Using inheritance, we can create SST, SSB 
struct Student{


};

//But what if I'm importing structs from an external library?
//How can we do this? -> We use generics (templates) 



//GENERICS (TEMPLATES)
//Student -> can be SST or SSB

struct SST{
    string name{"sanjana"};
    int marks{80};
};

struct SSB{
    int marks{20};
};



template<typename T>
void calculateMarks(T student) {
    cout << student.marks <<endl;
}


template<typename T>
struct List{
    T obj;

};

int main() {
    SST obj1;
    SSB obj2;   
    calculateMarks<SST>(obj1);
    calculateMarks<SSB>(obj2);


    //Example 2
    int x=12;
    int* ptrX = &x;
    List<int*> list;
    

    int y=15;
    // list.obj=&y; //The line below also stores the address
    list.obj=ptrX; 

    cout << x << endl;       //12
    cout << y << endl;       //15
    cout << list.obj<< endl; //0x3fcabffb6c


    cout << "-----------" << endl;
    List<int> other;
    other.obj=x;

    cout << other.obj << endl; //12, since we defined int as the type, we can only pass int 

    

}


/*
 In Java, do generics get resolved at runtime or compile time? - Compile time (with type erasure at runtime)
 In C++, generics (templates) are resolved at compile time
 Refer to templates.cpp file - the respective functions are created at compile time
*/