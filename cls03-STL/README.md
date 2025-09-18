- Pointers continued + memoey management.
```cpp
int*ptrX = &x;

//how do we access the value of x  -> this is also called dereference
*ptrX;
// - Little Endian and Big Endian
// char[4] - this is in continuos memory, 
char[4]= {0,1,2,3}
// char is 1 Byte, so 4 Bytes means 32 bits

now the array is stored in continuos memory

char [4] = { (00000000),(00000001),(00000010), (00000011),}
// ---------32------------------------------------------0 -> readingt from thr 32 big Endian
//now all of this are 32 bits, the num of this by attaching this is-if bits stay togther 

char [4] = { (00000000),(00000001),(00000010), (00000011),} 
//x86 all this platforms use little Endion format, ite reads in reverse fasdhion
//it reads per byte in the reverse fashion like 3-> 00000011 it reads 11000000

//it returns like {3,2,1,0}

```

### code,
- print a char array which prints 512
512 -> 0001 0000 0000 now, this char array should be in reverse, for the CPU, 



### Arrays in c++
