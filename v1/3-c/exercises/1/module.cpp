#include <iostream>
#include "module.h"

using namespace std;

void f1(int x, double y) {
    cout << "Called f1 with args: " << x << ", " << y << ". Returns void." << endl;
    return;
}

char f2() {
    cout << "Called f2 with no args. Returns char." << endl;
    return 'a';
}

int f3(int x) {
    cout << "Called f3 with arg: " << x << ". Returns int." << endl;
    return x;
}

float f4(double x, char c) {
    cout << "Called f4 with args: " << x << ", " << c << ". Returns float." << endl;
    return 3.14f;
}
