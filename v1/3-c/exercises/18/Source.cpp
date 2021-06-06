#include <iostream>
#include <vector>

using namespace std;

template <size_t N>
void print_array(int (&arr)[N]) {
    for (const int x : arr) {
        cout << x << ' ';
    }
    cout << '\n';
}

void print_vector(vector<int> &v) {
    for (int x : v) {
        cout << x << ' ';
    }
    cout << '\n';

}

int main() {

    const int array_size = 10;

    int a[array_size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //char c = 'z';
    int b[array_size] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

    print_array(a);
    print_array(b);

    a[5] = 'c';

    print_array(a);
    print_array(b);

    return 0;
}