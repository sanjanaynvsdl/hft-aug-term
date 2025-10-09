#include<iostream>
#include<cstdint>
using namespace std;


//Q: arry of chunks boxes with the sizes
struct Chunk{
    char bufferr[1024 * 1024* 1024]; //1024 * 1024 = 1mb, and 1mb * 1024 -> 1gb
};

//am jsut calling same thing as a memory pool,
//bcoz, memory pool is what has buffer and allocates memory
//this memory pool should handle all the structs not just boxes
//how can we write somehting that says, give me 10bytes, 12 bytes
//so, the user will pass the no, of bytes it's need
const uint64_t SIZE = 1024*1024*1024;
struct MemoryPool{
    char buffer[SIZE];
    uint64_t offset{0};

    
    //return type?, a POinter
    //we need to track how many bytes are consumed, -> in memory pool it's offset
    //if we have memory after 7th index which is stored in a pointer
    //if i write the return type, as Box which is a tight coupling, so void
    //so void* says i can be pointer to Box, char anything


    void* getMemory(size_t bytesNeeded) {
        if(offset + bytesNeeded > SIZE) {
            cout << "---------cannot allot more memory--------" << endl;
            return nullptr;
        }

        // void* ptrToOffset = &(buffer[offset]); //this returns the pointer to char
        //typecast we use the reinterpret
        void* ptrToOffset  = reinterpret_cast<void*>(&buffer[offset]);
        offset += bytesNeeded;
        return ptrToOffset;


    }
};





//since size cannot be negative always use, U for positive
struct Box{
    uint64_t size;
    uint64_t length;
    // uint64_t breadth;

};



int main () {
    cout << "hello " << endl;

    // Chunk chunk;
    //here -> whenever i intializse this, the stacks asks for 1gb, 
    //and results in a stack overflow so we get the Segmentation fault

    //todo: what change can we make to make this work -> add new key word
    //now it works -> using this chunk, i will declare boxes

    //if i place one box what is start idx and end idx of it, 
    //array -> 0 1 2 3 4 5 6 7 8 
    //box-1 ->  startIdx 0 to 15, 

    //uint64 64 bits -> 64/8 -> 8 bytes, 
    //size, lenght, width, 8+8+8 24 bytes 
    //as i commented  then 8+8 16 means the array of 0-15 needed for the box 1


    //BOX1 0 - 15
    //BOX2 16 - 31
    //now we use this chunk to allocate for the box

    Chunk* newChunk = new Chunk();
    // MemoryPool* mPool = malloc(sizeof(MemoryPool));
    MemoryPool* mPool = new MemoryPool(); //or we can also use malloc
    // Box* box1 = reinterpret_cast<Box*>(mPool->getMemory(sizeof(Box)));
    // box1->size=10;
    // cout << box1->size << endl; //using for loop now, 

    for(int i=1;i<=100;i++) {
        Box* box1 = reinterpret_cast<Box*>(mPool->getMemory(sizeof(Box)));
        box1->size=10;
        cout << box1->size << endl;
    }


    //now, we will make 1000 objects and see the sys calls
    //refer notions doc
     for(int i=1;i<=100;i++) {
        Box* box1 = new Box();
        box1->size=10;
        cout << box1->size << endl;
    }



}