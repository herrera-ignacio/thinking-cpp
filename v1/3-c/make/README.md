# Make: managing separate compilation

* Overview
* Make Activities
* Macros
* Suffix Rules
* [Automatic Variables](http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables)
* Default targets
* Example makefile

## Overview

When using *separate compilation*, you need some way to automatically compile each file and to tell the linker to build all the pieces, along with the appropriate libraries and startup code, into an executable file.

Most compilers allow you to do this with a single command-line statement. The problem with this approach is that the compiler will first compile each individual file, regardless of whether that file *needs* to be rebuilt or not. With many files in ap roject, it can become prohibitive to recompile everything if you've changed only a single file.

The solution is a program called **make**. The **make** utility manages all the individual files in ap roject by following instructions in a text file called a **makefile**.

When you edit some of the files in a project and type `make`, the **make** program follows the guidelines in the **makefile** to compare the dates on the source code files to the dates on the corresponding target files, and if a source code file date is more recent than its target file, **make** invokes the compiler on the source code file.

> **make** only recompiles the source code files that were changed and any other source-code files that are affected by the modified files. By using **make**, you don't have to re-compile all the files in your project every time you make a change, nor do you have to check to see that everything was built properly.

The **makefile** contains all the commands to put your project together.

## Make Activities

When you type `make`, the **make** program looks in the current directory for a file named **makefile**. This file lists dependencies between source code files. if a dependent file has an older date than a file it depends on, **make** executes the *rule* given after the dependency.

```makefile
# A comment
hello.exe: hello.cpp
    mycompiler hello.cpp
```

This example says that `hello.exe` (the target) depends on `hello.cpp`. When `hello.cpp` has a newer date than `hello.exe`, **make** executes the "rule" `mycompiler hello.cpp`.

The rules are not restricted to being calls to the compiler; you can call any program you want from within **make**. By creating groups of interdependent dependency-rule sets, you can modify your source code files, type `make` and be certain that all the affected files will be rebuilt correctly.

## Macros

Macros allow convenient string replacement.

The following example use a macro to invoke the C++ compiler. You can also add compiler flags, etc., to the macro, or use separate macros to add compiler flags.

```makefile
CPP = mycompiler

hello.exe: hello.cpp
    $(CPP) hello.cpp
```

## Suffic Rules

A suffix rule is a way to teach **make** how to convert a file with one type of extension (`.cpp` for example) into a file with another type of extension (`.obj` or `.exe`). A suffix rule tells **make** that it doesn'tt need explicit rules to build everything, but instead it can figure out how to build things based on their file extension.

```makefile
CPP = mycompiler
.SUFFIXES: .exe .cpp
.cpp.exe:
    $(CPP) $<
```

The `.SUFFIXES` directive tells **make** that it should watch out for any of the following file-name extensions because they have special meaning for this particular makefile. Next you see the suffix rule `.cpp.exe`, which says *"Here's how to convert any file with an extension of __cpp__ to one with an extension of __exe__"* (when the **cpp** file is more recent than the **exe** file). As before, the **$(CPP)** macro is used, but then you see something new: **$<**. This is one of **make**'s special built-in macros. The **$<** can be used only in suffix rules, and it means *"whatever prerequisite triggered the rule"* (sometimes called the *dependent*), which in this case translates to *"the __cpp__ file that needs to be compiled"*.

Once the suffix rules have been set up, you can simply say, for example, `make Union.exe`, and the suffix rule will kick in, even though there's no mention of "Union" anywhere in the **makefile**.

## Automatic Variables

> See all in http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables

```makefile
hello.o: hello.c hello.h
    gcc -c $< -o $@
```

Here, `hello.o` is the output file. This is what `$@` expands to. The first dependency is `hello.c`. That's what `$<` expands to.

## Default targets

After the macros and suffix rules, **make** looks for the first "target" in a file, and builds that, unless you specify differently.

```makefile
CPP = mycompiler
.SUFFIXES: .exe .cpp
.cpp.exe:
    $(CPP) $<
target1.exe: target1.cpp
target2.exe: target2.cpp
```

If you just type `make`, then `target1.exe` will be built (using the default suffix rule) because that's the first target that `make` encounters. To build `target2.exe` you'd have to explicitly say `make target2.exe`. This becomes tedious, so you normally create a default "dummy" target that depends on all the rest of the targets, like this:

```makefile
CPP = mycompiler
.SUFFIXES: .exe .cpp
.cpp.exe:
    $(CPP) $<
all: target1.exe target2.exe
```
This is a convention, so you can cause every executable in your project to be made simply by typing `make`. In addition, you can have other non-default target lists that do other things, such as `make debug` that rebuilds all your files with debugging wired in.

## Example makefile

If you have more than one `makefile` you can invoke a specific one with `make -f`.
