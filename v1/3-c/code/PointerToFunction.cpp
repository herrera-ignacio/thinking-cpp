#include <iostream>
using namespace std;

void func() {
    cout << "func() called" << endl;
}

int main() {
    void (*fp)(); // Define function pointer
    fp = func; // Initialize it
    (*fp)(); // Dereferencing calls the function

    void (*fp2)() = func; // Define and initialize another function pointer
    (*fp2)();
}