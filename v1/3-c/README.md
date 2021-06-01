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

### Modifying the outside object

Ordinarily, when you pass an argument to a function, a copy of that argument is made inside the function. This is referred to as **pass-by-value**.

When you're inside a function, temporary space is created to hold local variables for the duration of the function call, and they are initialized by copying the vlaues of the parameters. When you're inside the function, changing a local variable does not affect the outside object, since they are two separate locations in storage. This is where pointers come in handy. If we pass a *pointer* into a function, we are actually passing an alias to the outside object, enabling the function to modify the outside object.

## References

Pointers work roughly the same in C and in C++, but C++ adds an additional way to pass an address into a function. This is **pass-by-reference**. You can pass the address of an argument using a reference.

The difference between references and pointers is that *calling* a function that takes references is cleaner, syntatically, than calling a function that takes pointers.

