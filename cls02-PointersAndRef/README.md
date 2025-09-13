- struct is just like class in java
- Q1: let;s say we have x,y points and we want to find distance between them,
--Questions code on order struct
- pointers, 
- c++ does pass by value
- sp we use pointes

- singned and unsiged 
```cpp
int x;
//an memory of bits is being allocated
//- unsigned has 0 to 2^32 values coz a bit is being reserved for the sign 

// 4 bytes -> 32 bits
//is is the int alwasy takes 4bytes
//int is not alwasys 4 bytes

//why?

```

- Regiter size is 32 bits or 64 bits, 
- register is nothing but a hardware comp
- register is cpu word size
- RAm reads in batches
- why is c++ platform dependent?,
- 32 bit window size, 64 bit window size, registers need to understand better.
- we will understand why i'ts affects hft, nd pointers thing

-------how do we overcome this? srchitecture dependent 

```cpp
int32_t x;
int64_t y;
 //now this is independent of architecture
 //never use, in low-latency code
```

### What's the pointers usecase?
- history of pointers

- java doesn't allow us  to write to raw memory
- but the, c++ allows us in the RAM, to write to raw memoy @X04399 
- the concept is pointers - let's us to play with raw-memory in RAM, 

- IN CPU every address is a location
- like let's say what is the data type of addres it's hex right
- if we can store address in int, and int in intergesr how can we differenretiate them?

```cpp
int x=22;
// in RAM 4bytes will will alocates
//want to store address of x 

int* ptr = &x;
//this stores the address of the x,
//in ram creates another variables, size= 4bytes 
```
---------------------------- now, we will understand! the usage of pointers in the order example----------------------


- TCp sends bytes, we need to frame, 
- somoen send 32 bytes from a TCp 
- lets say i have rawy byutes 4 bytes of 32 bits
someone sent from TCp connection
- hey, im sending u a obj, but he send this 32 bits how do we need to read this, 

- from TCp example - check the conversion
