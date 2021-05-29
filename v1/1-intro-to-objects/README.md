# 1: Introduction to Objects

* Smalltalk: A Pure Approach to OOP
* Five stages of object design
* Guidelines for object development
* Extreme Programming

## Smalltalk: A Pure Approach to OOP

1. Everything is an object.

2. A program is a bunch of objects telling each other what to do by sending messages.

3. Each object has its own memory made up of other objects.

4. Every object has a type.

5. All objects of a particular type can receive the same message.

# Five stages of object design

1. __Object discovery__: Initial analysis of a program. Objects may be discovered by looking for external factors and boundaries, duplication of elements in the system, and the smallest conceptual units.

2. __Object assembly__: You'll discover the need for new members that didn't appear during discovery. The internal needs of the object may require other classes to support it.

3. __System construction__: More requirements for an object may appear at this later stage. As you learn, you evolve your objects. The need for communication and interconnection with other objects in the system may change the needs of your classes or require new classes.

4. __System extension__: As you add new features to a system, you may discover that your previous design doesn't support easy system extension.

5. __Object reuse__: As you change a class to adapt to more new programs, the general principles of the class will become clearer, until you have a truly reusable type. However, don't expect most objects from a system design to be reusable.

## Guidelines for object development

1. Let a specific problem generate a class, then let the class grow and mature during the solution of other problems.

2. Discovering the classes you need (and their interfaces) is the majority of the system design.

3. Don't force yourself to know everything at the beginning; learn as you go.

4. Start programming; get something working so you can prove or disprove your design. Don't fear that you'll end up with procedural-style spaghetti code, classes partition the problem and help control anarchy and entropy. Bad classes do not break good classes.

5. Always keep it simple. Little clean objects with obvious utility are better than big complicated interfaces. When decision points come up, use an *Occam's Razor approach*: Consider the choices and select the one that is simplest, because simple classes are almost always best. Smart small and simple, and you can expand the class interface when you understand it better, but as time goes on, it's difficult to remove elements from a class.

## Extreme Programming

> Extreme Programming Explained - Kent Beck, www.xprogramming.com

XP is both a philosophy about programming work and a set of guidelines to do it. Some of these guidelines are reflected in other recent methodologies, but the two most important and distinct contributions are *"write tests first"*, and *"pair programming"*.
