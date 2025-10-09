#include<iostream>
#include<cstdint>
using namespace std;


//Q: create sst, ssb student and write a function to accpet this obj and return the sum of their marks,
//now, using the inheritance we create sst, ssb, 
struct Student{


};

//but what if i was getting, im importing stuctrs from external librbary
//how can we do this, -> we make use of generics, 



//GENERICS 
//Student -> can be a sst or ssb

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


    //ex02
    int x=12;
    int* ptrX = &x;
    List<int*> list;
    

    int y=15;
    // list.obj=&y; //below line even this does store the address
    list.obj=ptrX; 

    cout << x << endl;       //12
    cout << y << endl;       //15
    cout << list.obj<< endl; //0x3fcabffb6c


    cout << "-----------" << endl;
    List<int> other;
    other.obj=x;

    cout << other.obj << endl; //12, since we defined as int as type we can only pass int, 

    

}


/*
 IN java do generics get reolved at run time or compile time? -compile time
 IN the, cpp the generics are reolved at the run time, 
 refer templates.cpp file, the respective fucntions are created at the compile time, 
*/