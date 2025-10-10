# Pointers and Memory Management

## Pointer Basics
```cpp
int *ptrX = &x;  // Create pointer to variable x
*ptrX;           // Access value through pointer (dereference)
```

## Memory Storage Concepts

### Little Endian vs Big Endian
- **Big Endian**: Reads data from left to right (most significant byte first)
- **Little Endian**: Reads data from right to left (least significant byte first)
- **x86 platforms** use Little Endian format

### Example with Char Array
```cpp
char array[4] = {0, 1, 2, 3};  // Each char is 1 byte (8 bits)
// Total: 4 bytes = 32 bits stored in continuous memory

// Binary representation:
// {00000000, 00000001, 00000010, 00000011}

// Little Endian reading (x86):
// Reads as: {3, 2, 1, 0} - in reverse order
```

## Exercise
- Print a char array that displays the number 512
- 512 in binary: 0001 0000 0000
- For CPU compatibility, store in reverse order

## Arrays in C++
