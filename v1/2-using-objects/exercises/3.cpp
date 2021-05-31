#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int counter = 0;
	ifstream in("3-data.txt");
	string buffer;

	while (in >> buffer)
		++counter;

	cout << "Whitespace-separated words: " << counter << endl;
}
