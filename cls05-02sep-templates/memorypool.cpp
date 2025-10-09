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

        offset += bytesNeeded;
        void* ptrToOffset = reinterpret_cast<void*>(&(buffer[offset]));
        return ptrToOffset;
    }
};

struct Box{
    uint64_t size;
    uint64_t length;
};


//as this memory pool can be used by any struct 
int main() {
    MemoryPool mPool;

    for(int i=0;i<100;i++) {
        Box* box = reinterpret_cast<Box*>(mPool.getMemory(sizeof(Box)));
        box->size=10;
        cout << "Box size is : " << box->size << endl;

    }

}
