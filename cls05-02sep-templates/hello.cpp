#include<iostream>
#include<cstdint>
using namespace std;


//Q: Array of chunks/boxes with sizes
struct Chunk{
    char bufferr[1024 * 1024* 1024]; //1024 * 1024 = 1MB, and 1MB * 1024 -> 1GB
};

//I'm calling this a memory pool
//because a memory pool has a buffer and allocates memory
//This memory pool should handle all structs, not just boxes
//How can we write something that says, "give me 10 bytes" or "12 bytes"?
//The user will pass the number of bytes needed
const uint64_t SIZE = 1024*1024*1024;
struct MemoryPool{
    char buffer[SIZE];
    uint64_t offset{0};


    //Return type: a pointer
    //We need to track how many bytes are consumed -> in memory pool, it's the offset
    //If we have memory after the 7th index, which is stored in a pointer
    //If I write the return type as Box, it's tight coupling, so use void
    //void* means it can be a pointer to Box, char, or anything


    void* getMemory(size_t bytesNeeded) {
        if(offset + bytesNeeded > SIZE) {
            cout << "---------cannot allot more memory--------" << endl;
            return nullptr;
        }

        // void* ptrToOffset = &(buffer[offset]); //This returns a pointer to char
        //To typecast, we use reinterpret_cast
        void* ptrToOffset  = reinterpret_cast<void*>(&buffer[offset]);
        offset += bytesNeeded;
       
        return ptrToOffset;


    };

    //same funciton, 
    void* getMemoryAddress(size_t neededBytes) {
        if(offset+neededBytes > SIZE) {
            return nullptr;
        }

        //1. get the ptr to the address

        void* ptrToAddress = reinterpret_cast<void*>(&buffer[offset]);
        offset+=neededBytes;
        return ptrToAddress; //every time it returns a pointer with that specific address
        //for the first iteration retunr buffer[0] box1 is stored fro 0,

    }
};





//Since size cannot be negative, always use uint (unsigned) for positive values
struct Box{
    uint64_t size;
    uint64_t length;
    // uint64_t breadth;

};



int main () {
    cout << "hello " << endl;

    // Chunk chunk;
    //Here, whenever I initialize this, the stack asks for 1GB
    //and results in a stack overflow, so we get a segmentation fault

    //TODO: What change can we make to fix this? -> Add 'new' keyword
    //Now it works -> using this chunk, I will declare boxes

    //If I place one box, what are the start index and end index?
    //Array -> 0 1 2 3 4 5 6 7 8
    //Box-1 -> startIdx 0 to 15

    //uint64_t: 64 bits -> 64/8 -> 8 bytes
    //size, length, width: 8+8+8 = 24 bytes
    //Since I commented width, then 8+8 = 16 means array indices 0-15 are needed for box 1

    //BOX1: 0-15
    //BOX2: 16-31
    //Now we use this chunk to allocate memory for the boxes

    Chunk* newChunk = new Chunk();
    // MemoryPool* mPool = malloc(sizeof(MemoryPool));
    MemoryPool* mPool = new MemoryPool(); //or we can also use malloc
    // Box* box1 = reinterpret_cast<Box*>(mPool->getMemory(sizeof(Box)));
    // box1->size=10;
    // cout << box1->size << endl; //Using a for loop now 

    for(int i=1;i<=100;i++) {
        Box* box1 = reinterpret_cast<Box*>(mPool->getMemoryAddress(sizeof(Box)));
        box1->size=10;
        cout << box1->size << endl;
    }


    //Now we'll make 1000 objects and see the system calls
    //Refer to Notion doc
     for(int i=1;i<=100;i++) {
        Box* box1 = new Box();
        box1->size=10;
        cout << box1->size << endl;
    }
}