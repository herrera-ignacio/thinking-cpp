#include <iostream>
using namespace std;

union Packed {
    char i;
    short j;
    int k;
    // long l;
    // float f;
    // double d;
};

int main() {
    cout << "sizeof(Packed) = " << sizeof(Packed) << endl;

    Packed x;
    x.i = 'c';
    cout << x.i << endl;

    // x.d = 1.23;
    // cout << x.d << endl;

    x.j = 2;
    // Everything besides x.j prints garbage
    cout << x.k << ' ' << x.i << ' ' << x.j << endl;
}