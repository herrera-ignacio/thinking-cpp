# 2: Making & Using Objects

* Compilation Process
* Declaration vs definition
* ODR: One Definition Rule
* Using libraries   
  * C Libraries
* Namespaces
* Compiling

## Compilation Process

Compilation starts by running a *preprocessor* on the source code. The preprocessor is a simple program that replaces patterns in the source code with other patterns the programmer has defined(using *preprocessor directives*. Preprocessor directives are used to save typing and to increase the readability of the code.

> The pre-processed code is often written to an intermediate file.

> The design of C++ is meant to discourage much ogf the use of the preoprocessor, since it can cause subtle bugs.

Compilers usually do their work in two passes.

The first pass parses the pre-processed code. The compiler breaks the source code into small units and organizes it into a structure called a *tree*. In the expression `A + B` the elements `A`, `+`, and `B` are leaves on the parse tree.

A *global optimized* is sometimes used between the first and second passes to produce smaller, faster code.

In the second pass, the *code generator* walks trough the parse tree and generates either assembly language code or machine code for the nodes of the tree. if the code generator creates assembly code, the assembler must then be run. The end result in both cases is an object module (`.o` or `.obj`). A *peephole optimizer* is sometimes used in the second pass to look for pieces of code containing redundant assembly-language statements.

> The use of the word "object" to describe chunks of machine code is an unfortunate artifact. The word came into use before OOP was in general use. "Object" is used in the same sense as "goal" when discussing compilation, while in OOP it means "a thing with boundaries".

In the last phase of the compilation process, the *linker* combines a list of object modules into an executable program that can be loaded and run by the operating system. When a function in one object modules makes a reference to a function or vaiable in another object module, the linker resolves these references; it makes sure that all the external functions and data you claimed existed during compilation do exist. The linker also adds a special object module to perform start-up activities.

The linker can search through special files called *libraries* in order to resolve all its references. A library contains a collection of object modules in a single file, and is created and maintained by a program called a *librarian*.

## Declaration vs definition

A *declaration* introduces a name, an identifier, to the compiler.

> Declaration tells the compiler "This function or this variable exists somewhere, and here is what it should look like."

A *definition* on the other hand, allocates storage for the name.

> Definition says "Make this variable/function here."

A definition can also be a declaration. If the compiler hasn't seen the name `x` before you define `int x;`, the compiler sees the name as a declaration and allocates storage for it all at once.

## ODR: One Definition Rule

You can declare a variable or a function in many different planes, but there must be only one definition in C and C++.

When the linker is uniting all the object modules, it will usually complain if it finds more than one definition for the same function or variable.

## Using libraries

1. Include the library's header file.
2. Use the functions and variables in the library.
3. Link the library into the executable program.

If the linker cannot find the definition in the list of object modules, it searches the libraries. Libraries have some sort of indexing so the linker doesn't need to look through all the object modules in the library, it just looks in the index. When the linker finds a definition in a library, the entire object module is linked into the executable program (not just the function definition, neither the whole library).

### C Libraries

The entire C library is included by default into Standard C++. You can use them with the traditional `.h` extension, or the more modern C++ include style by prepending a `c` before the name:

```c++
#include <stdio.h>
#include<stdlib.h>
```

Is equal to:

```c++
#include <cstdio>
#include <cstdlib>
```

## Namespaces

The `namespace` keyword is a mechanism in Standard C++ to prevent name collision. Each set of C++ definitions in a library or program is "wrapped" in a namespace, and if some other definition has an identical name, but is in a different namespace, then there is no collision.

## Compiling

To compile your programs, first you need a compiler.

In case of Windows we will need `g++`, `gdb`, and `make`. You can get those in the [Cygwin Project](https://sourceware.org/cygwin/).
