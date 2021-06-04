#include <iostream>
#include <string>

using namespace std;

int main() {
	char c;
	bool stop = false;

	while (!stop) {
		cout << "Type secret code (q for exit): " << endl;
		cin >> c;
		cout << "You typed -> " << c << endl;

		switch (c) {
		case 'q':
			stop = true;
			break;
		case 'n':
			cout << "Success" << endl;
			break;
		default:
			cout << "Try again..." << endl;
			break;
		}
	}

	return 0;
}