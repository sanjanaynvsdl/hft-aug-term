#include<iostream>
#include<cstdint>

using namespace std;

//Q: Write a memory pool for the stack, because if we need size less than 8MB
//why would we even use heap?

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

//Hard-coded size to take 100, 5
struct Box{
    uint64_t size{100};
    uint64_t length{5}; //This doesn't apply unless the constructor is called
    
};


//This memory pool can be used by any struct 
int main() {
    // MemoryPool* mPool = new MemoryPool();
    // Box* box1 = reinterpret_cast<Box*>(mPool->getMemory(sizeof(Box)));
    // cout << box1->size << endl; //Prints 0
     //Even though the size of Box is hard-coded
     //the constructor of Box is not being called, so it's 0


    MemoryPool* mPool = new MemoryPool();
    //This is how we call the constructor on allocated memory
    //Since I can use memory pool to store any struct or object, I use this

    Box* box1 = reinterpret_cast<Box*>(mPool->getMemory(sizeof(Box)));
    new (box1) Box(); //Just call the constructor since I already have memory (placement new)
    char* ch = reinterpret_cast<char*>(mPool->getMemory(1)); //char -> 1 byte
    *ch='k';
    //Another extra case: after declaring this ch, now I want another box
    
    Box* box2 = reinterpret_cast<Box*>(mPool->getMemory(sizeof(Box)));
    new (box2) Box();

    cout <<  "------Box1 size is : "<<box1->size << endl; //Prints 100
    cout << "--------Value is : " << ch << endl; //Prints k
    cout << "-------Box 2 length is : " << box2->length << endl;

    //box1 offset starts at index 0
    //char offset starts at index 16
    //box2 offset starts at index 17
    //--------------------------------------------
    //This runs successfully, but if we remove some compiler checks
    //there are runtime errors
    //Error: constructor called on misaligned address
    //On commenting out char ch, it works fine

    //Case 1: box1, ch, box2 -> error
    //Case 2: box1, box2 -> works
    //Case 3: box1, box2, char ch -> works
    //Why does this happen?

    /*
    Box size = 16 bytes
    box1: 0-15
    char ch: 1 byte (it's a multiple of 1)
    box2 can't start at 17 because it's not a multiple of 16 (alignment issue)

    It runs and prints, but it's slower because it makes multiple CPU calls
    */


     
    

}
