#include<iostream>
#include<cstdint>

using namespace std;

//Q: write a memory pool for the stack, because if need size less the 8mb
//why would i even use heap

const uint64_t SIZE = 1024 * 1024 * 2;

struct MemoryPool{
    char buffer[SIZE];
    uint64_t offset{0};

    void* getMemory(size_t bytesNeeded) {
        if(offset+bytesNeeded > SIZE) {
            cout << " Memory used " << endl;
            return nullptr;
        }
        // cout << "Current offset is : " << offset << endl;

        offset += bytesNeeded;
        void* ptrToOffset = reinterpret_cast<void*>(&(buffer[offset]));
        return ptrToOffset;
    }
};

//harded size to takw 100, 5
struct Box{
    uint64_t size{100};
    uint64_t length{5}; //this don't apply until unless the constructor is being called
    
};


//as this memory pool can be used by any struct 
int main() {
    // MemoryPool* mPool = new MemoryPool(); 
    // Box* box1 = reinterpret_cast<Box*>(mPool->getMemory(sizeof(Box)));
    // cout << box1->size << endl; //prints 0, 
     //even thouhg the size of box is being hard coded, 
     //the constructor of box is not begin called so, it's 0,


    MemoryPool* mPool = new MemoryPool(); 
    //this is how we call the constructor on a allocated memory,
    //since i can use memory pool to store any struct or obj i use this

    Box* box1 = reinterpret_cast<Box*>(mPool->getMemory(sizeof(Box)));
    new (box1) Box(); //just call the construcor as i already have memory
    char* ch = reinterpret_cast<char*>(mPool->getMemory(1)); //char -> 1 byte
    *ch='k';
    //anothe extra case, after declaring this ch, now i want another box
    
    Box* box2 = reinterpret_cast<Box*>(mPool->getMemory(sizeof(Box)));
    new (box2) Box();

    cout <<  "------Box1 size is : "<<box1->size << endl; //prints 100, 
    cout << "--------Value is : " << ch << endl; //prints k, 
    cout << "-------Box 2 length is : " << box2->length << endl;

    //box1 offset starts at idx -0
    //char offset start at idx -> 16
    //box offset start at idx -> 17
    //--------------------------------------------
    //this has run succefully but if we remove some checks, compiler ones
    //there are run time errors, 
    //error: constructor called on misaligned address
    //on commentin char, ch, it works fine

    //case-1 box1, ch, box2 -> error
    //case-2 box1, box2 -> words
    //case-3 box1, box2, char ch -> works
    //why does this happen?,

    /*
    Box size = 16 bytes 
    box1 0-15 
    char ch 1 byte, it's multiple of 1
    box2 can't start at 17 as it's not a multiple of 16

    it runs and prints but it's a bit slow, it makes multiple cpu calls
    */


     
    

}
