#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string userInput;
	string word;
	ifstream in("7.cpp");

	while (getline(in, word)) {
		cout << "Press a key to continue..." << endl;

		cin.get();

		cout << word << endl;
	}
}

