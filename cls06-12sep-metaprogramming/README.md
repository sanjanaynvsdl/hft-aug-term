## Recap
1. Structure padding
2. Alignments

### Classes Quizzes
- Why do functions not take space?
- Functions work differently

```cpp
struct Student{
    int x1;
    int x2;
    static int something1;
    static int something2;
    char y;
    void f1() {}
    void f2() {}
};
```

Size = 12 (x1=4, x2=4, char=1, padding=3). Static members and functions do not affect struct size.

---

## Templates and Metaprogramming

**Reference:** https://cppinsights.io/ (use this for template resolutions)

### Three Template Method Signatures

#### 1. T obj - Pass by Value
- Ignores everything, creates a copy
- Ignores CV qualifiers (const, volatile)

```cpp
template<typename T>
void appendHello(T obj) {};

int main() {
    const int x = 12;
    appendHello(x); //creates copy, ignores const
}
```

#### 2. T& obj - Lvalue Reference
- Takes reference, doesn't ignore CV qualifiers
- Issue: r-values give compilation errors

```cpp
template<typename T>
void fn(T& obj) {}

int main() {
    const int x = 12;
    fn(x); //takes const as ref
}
```

#### 3. T&& obj - Universal Reference
- Accepts both l-values and r-values
- Refer to [template01.cpp](template01.cpp)

---

### Lvalues and Rvalues
- **lvalue**: has a name (e.g., variables)
- **rvalue**: doesn't have a name (e.g., temporaries, literals)

---

### Template Specialization
- Used to handle specific cases like pointers
- Example: obj.id vs obj->id
- Refer to [template02.cpp](template02.cpp)

---

### Topics to Study
- Object slicing
- Downcasting and upcasting
- In C++ we have to work with pointers for inheritance
