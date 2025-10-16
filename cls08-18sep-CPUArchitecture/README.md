# Move Semantics + CPU Architecture

---

## Move Semantics

### Example

```cpp
getVector() {
    return new Vector;
}

Vector v = getVector();
```

### Flow
1. `getVector()` creates `v = {1, 2, 3}`.  
2. The pointer to `v` is stored on the stack, and `{1, 2, 3}` is stored in the heap.  
3. When the function ends, local variables are destroyed, but since it returns a new object, the main function creates a copy.  
4. This copy process consumes memory and time.  

**Idea:**  
Instead of creating a copy, we can transfer ownership of the heap memory using the **move constructor**.  
This avoids unnecessary copying and increases performance.

---

## CPU Architecture

### What is a Process?
A **process** is an instance of a program that is being executed.  
Each process runs independently with its own memory space, registers, and page table managed by the operating system.
Ex- chrome, spotify etc 

---

### Why We Can’t Directly Access RAM
1. Even if we try to make two addresses point to the same RAM address, it won’t work.  
2. Our program never has full access to the entire RAM.  
3. The **Operating System (OS)** controls how each process accesses memory using **Virtual Memory**.

---

### Virtual Memory and Page Table
- Assume we have 16 GB RAM.  
- Each program (process) does not directly access all 16 GB.  
- The OS creates a **Page Table** for each process.  
- The Page Table maps **Virtual Memory (used by process)** → **Physical Memory (RAM frames)**.  

Example:

| Virtual Memory | Physical Memory |
|-----------------|----------------|
| 1               | 10101          |
| 2               | 312312         |

Each process has its own Page Table, so even if two processes use the same pointer value, they refer to different physical addresses — no conflict.

---

### Page Table and Frames
- Memory is divided into **frames** (each of size 4 KB).  
- The Page Table maps frames, not individual bytes.  
- This means memory is managed frame by frame.  

---

### Example Calculation
If:
- RAM = 16 GB  
- Frame size = 4 KB  

Then the total number of frames = `16 GB / 4 KB = 4 million frames`.

Each process has its own mapping (virtual → physical).  

If one process uses 8 MB worth of pages, then theoretically:
`16 GB / 8 MB ≈ 2 × 1024` processes can exist simultaneously (in ideal conditions).

---

### Page vs Frame
- **Page** → Software term (virtual memory block).  
- **Frame** → Hardware term (physical memory block).  

---

### Addressing in Page Table
- Suppose `int x = 64;`  
  The address of `x` is 64 bits (since pointer = 8 bytes → 8 × 8 = 64 bits).  
- The Page Table doesn’t store all 64 bits.  
  It stores only **20 bits** to identify the frame number.  
- The remaining bits are used as an **offset** within that frame.

---

### TLB (Translation Lookaside Buffer)
- Every time we access a variable (`x` or `y`), the CPU looks at the Page Table to find where it exists in RAM.  
- This lookup is slow, so CPUs have a small hardware cache called **TLB**.  
- TLB stores recent address translations (virtual → physical).  
- If an address is found in TLB → **fast access**.  
- If not → fallback to the Page Table (slower).  
- Page Table lives in RAM; TLB is separate hardware inside the CPU.

---

### Page Fault
- If a process tries to access a page that is not currently in physical memory, a **page fault** occurs.  
- The OS then loads that page from disk into RAM.  
- Page faults are expensive (slow down performance).

---

### Memory Limit Example
If you have:
- 16 GB RAM  
- A process tries to use 100 GB  

→ It won’t directly fit in RAM.  
But through **Virtual Memory**, the OS uses **disk storage** (swap area) to simulate more memory.  
This allows large programs to run even when physical RAM is smaller, but performance will drop.

---

### Flow Diagram: Memory Access

```
CPU
 │
 │ (1) Request memory address
 ▼
TLB (fast cache for address mapping)
 │
 ├─ Hit → Return physical address
 └─ Miss
     │
     ▼
     Page Table (in RAM)
     │
     ▼
     Physical Memory (RAM Frames)
```

---

### Flow Diagram: Page Table & Virtual Memory

```
Process (Virtual Memory)
     │
     │ (address translation)
     ▼
 Page Table (per process)
     │
     │ (maps virtual → physical)
     ▼
Physical Memory (RAM Frames)
```


Process (Virtual Memory)
   |
   |  uses addresses like 0x1000, 0x2000, etc.
   ↓
Page Table (per process)
   |
   |  translates virtual address → physical address
   ↓
Physical Memory (RAM)
   |
   |  stores actual data in 4KB frames
   ↓
Hardware (CPU)



each process gets its own page table when it starts.