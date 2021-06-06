/**
Define a function that takes a double argument and returns an int.
Create and initialize a pointer to this function, and call the function through your pointer.
**/

#include <iostream>

using namespace std;

int func(double);

int main() {
    int (*funcPtr)(double);
    funcPtr = &func;

    (*funcPtr)(2.2);

    return 0;
}

int func(double d) {
    cout << "Called func(" << d << ")" << endl;

    return 0;
}
