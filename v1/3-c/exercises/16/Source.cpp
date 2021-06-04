#include <iostream>

using namespace std;

enum COLORS { RED = 1, GREEN = 3, WHITE = 5, BLUE, BLACK };

int main() {
    COLORS colors[5] = {RED, GREEN, WHITE, BLUE, BLACK};

    for (COLORS color : colors)
        cout << color << endl;

    return 0;
}