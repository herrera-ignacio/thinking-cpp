# The C in C++

* Using the C function library
* Creating your own libraries with the librarian
* Controlling execution
* Data Types
  * bool, true & false
  * Specifiers
* Pointers
  * Modifying the outside object
* References
* Scoping
* Storage Allocation
* Preprocessor Macros Overview
* Operators
* Explicit Casting
* `struct`: Composite type creation
* Clarifying programs with `enum`
* Saving memory with `union`
* Arrays
* Command-line Arguments
* Function pointer
* Array of pointers to function
* [Make: managing separate compilation](./make)

## Using the C function library

All the functions in your local C function library are available in C++.

> Many compilers include a lot of extra functions that make life even easier and are tempting to use, but are not part of the Standard C library.

The formula for using a library function is as follows:

1. Find the function in your programming reference.
2. Use `#include` to declare proper header file containing the function prototype.
3. Call function from your source code.

The linker searches the Standard library by default.

## Creating your own libraries with the librarian

Most programming packages come with a librarian that manages groups of object modules. Each librarian has its own commands, but the general idea is:

1. Make a header file containing the function prototypes.
2. Put header file somewhere in the preprocessor's search path.
    * Either in the local directory (`#include "header"`)
    * Or in the include directory (`#include <header>`)
3. Take all object modules and hand them to librarian along with a name for the finished library.
4. Place the finished library where the other libraries reside so the linker can find it.

> You will have to add something to the command line so the linker knows to search the library for the functions you call. This vary from system to system.

## Controlling execution

* if-else
* while
* do-while
* for
* switch
* goto

Inside the body of any of the looping constructs **while**, do-**while**, or **for**, you can control the flow of the loop using `break` and `continue`. `break` quits the loop without executing the rest of the statements in the loop. `continue` stops the execution of the current iteration and goes back to the beginning of the loop to begin a new iteration.

## Data Types

The Standard C specification for built-in types (which C++ inherits) doesn't say how many bits each of the built-in types must contain. Instead, it stipulates the minimum and maximum values that the built-in type must be able to hold.

C and C++ have **four basic built-in data types**, described here for a binary-based machine:

* `char`: character storage and uses a minimum of 8 bits (1 byte) of storage, although it may be larger.
* `int`: integral number and uses a minimum of 2 bytes of storage.
* `float` and `double`: floating-point numbers, usually in IEEE floating-point number, for single precision and double-precision floating point respectively.

### bool, true, & false.

Before `bool` became part of Standard C++, everyone tended to use different techniques in order to produce Boolean-like behavior, which produced portability problems and could introduce subtle errors.

The Standard C++ `bool` type can have two states, expressed by the built-in constants `true` (which converts to an itnegral one) and `false` (which converts to an integral zero).

### Specifiers

Specifiers modify the meanings of the basic built-in types and expand them to a much larger set. There are four specifiers: **long**, **short**, **signed**, and **unsigned**.

**long** and **short** modify the maximum and minimum values that a data type will hold.

A plain `int` must be at least the size of a `short`. The size hierarchy for integral types is: **short int**, **int**, **long int**. All the sizes could conceivably by the same, as long as they satisfy the minimum/maximum value requirements. On a machine with a 64-bit word, for instance, all the data types might be 64 bits.

The size hierarchy for floating point numbers is: **float**, **double**, and **long double**. There are no short floating-point numbers.

The **signed** and **unsigned** specifiers tell the compiler how to use the sign bit with integral types and characters (floating-point numbers always contain a sign). An **unsigned** number does not keep track of the sign and thus has an extra bit available, so it can store positive numbers twice as large as the positive numbers that can be stored in a **signed** number. **signed** is the default and is only necessary with **char**, **char** may or my not default to **signed**. By specifying **synged char**, you force the sighn bit to be used.

## Pointers

All elements of your program are located somewhere in memory. Memory is typically laid out as a sequential series of memory locations, we usually refer to these locations as eight-bit *bytes* but actually the size of each space depends on the architecture of the particular machine and usually called that machione's *word size*. Each space can be uniquely distinguished from all other spaces by its *address*.  

> Each of the elements in this program has a location in storage when the program is running. Even the function occupies storage. As you'll see, it turns out that what an element is and the way you define it usually determines the area of memory where that element is placed.

The `&` operator, when preceding an identifier name, will produce the address of that identifier.

C and C++ have a special type of variable that holds an address, a **pointer**. This way you can store an address inside another variable for later use. The operator that defines a pointer is `*` and you must specify the type of variable it points to. The compiler knows that it isn't multiplication because of the context in which it is used, as you will see.

> You can state that a pointer is a `void*`, meaning that any type of address at all can be assigned to that pointer. You lose any information about what type it is, so before oyu can use the pointer, you must cast it to the correct type.

### Modifying the outside object

Ordinarily, when you pass an argument to a function, a copy of that argument is made inside the function. This is referred to as **pass-by-value**.

When you're inside a function, temporary space is created to hold local variables for the duration of the function call, and they are initialized by copying the vlaues of the parameters. When you're inside the function, changing a local variable does not affect the outside object, since they are two separate locations in storage. This is where pointers come in handy. If we pass a *pointer* into a function, we are actually passing an alias to the outside object, enabling the function to modify the outside object.

## References

Pointers work roughly the same in C and in C++, but C++ adds an additional way to pass an address into a function. This is **pass-by-reference**. You can pass the address of an argument using a reference.

The difference between references and pointers is that *calling* a function that takes references is cleaner, syntatically, than calling a function that takes pointers.

## Scoping

> Scoping rules tell you where a variable is valid, where it is created, and where it gets destroyed (i.e, goes out of scope).

The scope of a variable extends *from the point where it is defiend to the first closing brance that matches the closest opening brace before the variable was defined*. That is scope is defined by its "nearest" set of braces.

A variable can be used only when inside its scope. Scopes can be nested, and you can access a variable in a scope that encloses the scope you are in.

## Storage Allocation

* __Global__: Defined outside all function bodies and are available to all parts of the program (even code in other files). They are unaffected by scopes and are the lifetime lasts until program ends. If is declared using the `extern` keyword in another file, the data is available for use by the second file, when compiler encounters the declaration `extern T identifier`, it knows that the definition for *identifier* must exist somewhere as a global variable.

* __Local__: Occur within a scope; they are "local" to a function. They are often called *automatic* variables because they automatically come into being when the scope is entered and automatically go away when the scope closes. The keyword `auto` makes this explicit, but local variables default to `auto` so it is never necessary to declare something as an `auto`.
  
  * `register`: Tells the compiler a hint: "Make accesses to this variable as fast as possible". Though, there is no guarantee that the variable will be placed in a register or even that the access speed will increase, it is only a hint to the compiler.
    * Cannot take or compute the address.
    * Can be declared only within a block.

  * `static`: You can define a function's local variable to be `static` and give it an initial value. The initialization is performed only the first time the function is called, and the data retains its value between function calls. This way, a function can "remember" some piece of information between function calls.

* __Constants__: Tells the compiler that a name represents a constant. Any data type, bult-in or user-defined, may be defined as `const`. It has a scope, just like a regular variable, so you can "hide" a *const* inside a function and be sure that the name will not affect the rest of the program.

* __Volatile__: It tells the compiler "You never know when this will change", and prevents the compiler from perfoming any optimizations based on the stability of that variable.

## Preprocessor Macros Overview

You can save typing and by using macros. See the following example:

```cpp
#include <iostream>
using namespace std;

// Macro to display a string and a value
#define PRINT(STR, VAR) \
  cout << STR "  = " << VAR << endl

int main () {
  int i = 1;
  PRINT("i", i);
}
```

## Operators

* **Assignment & Mathematical**
  * `-`, `+`, `/`, `*`, `%`
  * `=`, `-=`, `+=`, `/=`, `*=`, `%=`
* **Relational**
  * `<`, `>`, `<=`, `>=`, `==`, `!=`
* **Logical** (`bool`)
  * `&&`, `||`
* **Bitwise** (`char`, `int`, and `long`)
  * `&` and, `|` or, `^` xor, `~` not
  * `&=`, `|=`, `^=`
* **Shift**
  * `<<` and `>>`
  * `<<=` and `>>=`
* **Unary**
  * `!` not, `-`, and `+`.
  * `&` address-of, `*` and `->` dereference
  * `(desired-type w/modifiers) value` Cast operators in C and C++ (i.e, `unsigned long a = (unsigned long int)b;`)
  * `new` and `delete` in C++
* **Ternary**
  * `(boolean expression) ? true-case : false-case`
* `sizeof`: Information about the amount of memory allocated for data items.

### Ternary example

```cpp
a = --b ? b : (b = -99);
```

Here, the conditional produces the rvalue. `a` is assigned to the value of `b` if the result of decrementing `b` is nonzero. If `b` became zero, `a` and `b` are both assigned to `-99`. `b` is always decremented, but it is assigned to `-99` only if the decrement causes `b` to become 0.

A similar statement can be used just for its side effects:

```cpp
--b ? b : (b = -99)
```

Here the second `b` is sueprfluous.

## Explicit Casting

* `static_cast`: For "well-behaved" and "reasonably well-behaved" casts, including automatic implicit type conversions, narrowing conversions, forcing a conversion from a `void*`, and static navigation of class hierarchies.

* `const_cast`: Convert from a `const` or from a `volatile`.

* `reinterpret_cast`: This is the least safe of the casting mechanisms, and the one most likely to produce bugs. It prentends that an object is just a bit pattern that can be treated as if it were an entirely different type of object. The key is that you'll need to cast back to the original type to use it safely. It is typically used only for bit twiddling or some other mysterious purpose.

* `dynamic_cast`: For type-safe downcasting.

## `struct`: Composite type creation

> `struct` is the fundation for `class` in C++.

The simplest way to create more sophisticated types is simply to alias a name to another name via `typedef <existing-type-description> <alis-name>`. It is used just to prevent extra keystrokes.

```cpp
typedef unsigned long ulong;
```

`struct` is a way to collect a group of variables into a structure. You can make many instances of this "new" type of variable.

```cpp
struct Structure1 {
  char c;
  int i;
  float f;
  dobule d;
};

int main() {
  struct Structure1 s1;
  s1.c = 'a';
  s1.i = 1;
  s1.f = 3.14;
  s1.d = 0.00093;
}
```

```cpp
typedef struct { ... } Structure2;

Structure2 s1;
```

```
typedef struct SelfReferential {
  int i;
  SelfReferential* sr;
} SelfReferential;
```

## Clarifying programs with `enum`

An enumerated data type is a way of attaching names to numbers, thereby giving more meaning to anyone reading the code.

```cpp
enum ShapeType {
  circle,
  square,
  rectangle
};

int main() {
  ShapeType shape = circle;
  
  switch(shape) {
    case circle: /* circle stuff */ break;
    case square: /* square stuff */ break;
    case rectangle: /* rectangle stuff */ break;
  }
}
```

If you don't like the way the compiler assigns values, you can do it yourself:

```cpp
enum ShapeType {
  circle = 10,
  square = 20,
  rectangle = 50,
  pentagon
};
```

## Saving memory with `union`

Sometimes a program will handle different types of data using the same variable. In this situation, you can create a `struct` containing all the possible different types you might need to store, or you can use a `union`. A `union` piles all the data into a single space; it figures out the amount of space necessary for the largest item you've put in the `union` and makes that the size of the `union`.

Anytime you place a value in a `union`, the value always starts in the same place at the beginning of the `union`, but only uses as much space as is necessary. Thus, you create a "super-variable" capable of holding any of the `union` variables. All the addresses of the `union` variables are the same (in a class or `struct`, the addresses are different).

```cpp
union Packed {
  char i;
  short j;
  int k;
  long l;
  float f;
  double d;
  // The union will be the size of a double,
  // since that's the largest element.
};

int main() {
  Packed x;
  x.i = 'c';
  cout << x.i << endl;
  x.d = 3.14159
  cout << x.d << endl;
}
```

The compiler performs the proper assignment according to the union member you select.

## Arrays

```cpp
int a[10]
<type> <identifier>[<size>]
```

Array access is extremely fast. However, if you index past the end of the array, there is no safety net, you'll step on other variables. The other drawback is that you must define the size of the array at compile time; if you want to change the size at runtime you can't do it with the syntax above. The C++ `vector` provides an array-like object that automatically resizes itself, so it is usually a much better solution if your array size cannot be known at compile time.

### Pointers and arrays

The identifier of an array is unlike the identifiers of ordinary variables. When you give the name of an array, without square brackets, you get the starting address of the array.

One way to look at the array identifier is a **read only pointer to the beginning of an array**. And although we can't change the array identifier to point somewhere else, we *can* create another pointer and use that to move around in the array.

```cpp
int main() {
  int a[10];
  int* ip = a;
  for (int i = 0; i < 10; i ++)
    ip[i] = i * 10;
}
```

## Command-line Arguments

C and C++ have a special argument list for `main()`:

```cpp
int main(int argc, char* argv[]) { /* ... */ }
int main(int argc, char** argv[]) { /* ... */ }
```

The first argument is the number of elements in the array, which is the second argument and is always an array of `char*`, because the arguments are passed from the command line as character arrays. Each whitespace-delimited cluster of characters on the command line is turned into a separate array argument.

## Function Pointer 

```cpp
void (*funcPtr)();
```

When you are looking at a complex definition like this, the best way to attack it is to start in the middle and work your way out.

To review, "start in the middle" (`funcPtr` is a ..."), go to the right (nothing there, you're stopped by the right parenthesis), go to the left and find the `*` ("... pointer to a ... "), go to the right and find the empty argument list (" ... function that takes no arguments ... "), go to the left and find the `void`. _funcPtr is a pointer to a function that takes no arguments and returns void_.

## Arrays of pointers to functions

To select a function, yo just index into the array and dereference the pointer. This supports the concept of *table-driven code*. Instead of using conditionals or case statements, you select functions to execute based on a state variable (or a combination). This kind of design can be useful if you often add or delete functions from the table or want to create/change such a table dynamically.