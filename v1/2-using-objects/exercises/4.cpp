#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int counter = 0;
	ifstream in("3-data.txt");
	string word;
	string buffer;

	cout << "Input word to count: " << endl;
	cin >> word;

	while (in >> buffer) {
		if (buffer == word)
			++counter;
	}

	cout << "Occurences: " << counter << endl;
}