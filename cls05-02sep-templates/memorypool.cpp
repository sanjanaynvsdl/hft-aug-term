#include<iostream>
#include<cstdint>

using namespace std;

//Q: Write a memory pool for the stack, because if we need size less than 8MB
//why would we even use heap?

const uint64_t SIZE = 1024 *16;  // 2MB

struct MemoryPool{
    char buffer[SIZE];
    uint64_t offset{0};

    void* getMemory(size_t bytesNeeded) {
        if(offset+bytesNeeded > SIZE) {
            cout << " Memory used " << endl;
            return nullptr;
        }

        void* ptrToOffset = reinterpret_cast<void*>(&(buffer[offset]));
        offset += bytesNeeded;
        return ptrToOffset;
    }
};

struct Box{
    uint64_t size;
    uint64_t length;
};


//This memory pool can be used by any struct 
int main() {
    MemoryPool mPool;

    for(int i=0;i<100;i++) {
        Box* box = reinterpret_cast<Box*>(mPool.getMemory(sizeof(Box)));
        box->size=10;
        cout << "Box size is : " << box->size << endl;

    }

}
