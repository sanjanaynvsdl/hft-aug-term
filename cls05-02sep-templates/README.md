## Recap
mmap-sys calls, even brk gets the memory
1.we have limitations with the stack and the stack size is usally not more than 8mb, 
2.use heap, and make 1000 nodes, now how can we optimize the 1000 sys calls
3.preallocate the memory and use it, 
4.get 1gb at the start using the mmap, this is what the battle of memeory pool is, 


### Q: we have a array of any size, given a vector of boxes, print the array like first 4-bytes are for the first one, 
- i have array of size 10, i get two boxes one is 6 and one is 4, 
- refer hello.cpp

### discussion on the Uint64_t why should we declare like this for sizes
- as the sizes cannot cbe negative we use this, 
- now, why do we specifiy the bits always because we don't know if its taking 32 bit or 64 bits so it's alwasy good practice to do like this, 
- we can use size_t as the size type