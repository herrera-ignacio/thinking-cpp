#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Must provide an integer" << endl;
        exit(1);
    }

    int num = atoi(argv[1]);
    bool is_prime = num > 1 ? true : false;

    for (int i = 2; i < num && is_prime; i++) {
        if (num % i == 0) {
            is_prime = false;
        }
    }

    string res = is_prime ? "Yes" : "No";
    
    cout << "Is Prime? " << res << endl;
}