#include <iostream>

using namespace std;

const string SECRET_CODE = "secret";
const string EASTER_EGG = "iam";

int main(int argc, char* argv[]) {
    string input;
    int encoded_input;
    bool stop = false;

    while (!stop) {
        cout << "(Enter 'q' to exit)" << endl;
        cout << "Enter secret code: " << endl;
        cin >> input;

        if (input == SECRET_CODE)
            encoded_input = 1;
        else if (input == EASTER_EGG)
            encoded_input = 2;
        else if (input == "q")
            encoded_input = 0;
        else
            encoded_input = 99;

        switch (encoded_input) {
            case 1:
                cout << "Access granted" << endl;
                break;
            case 2:
                cout << "You discovered an easter egg" << endl;
                break;
            case 0:
                stop = true;
                cout << "Closing..." << endl;
                break;
            default:
                cout << "Try again..." << endl;
                break;
        }
    }

    return 0;
}