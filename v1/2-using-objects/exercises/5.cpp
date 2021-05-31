#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	vector<string> words;
	ifstream in("5.cpp");
	string word;

	while (in >> word)
		words.push_back(word);

	for (int i = words.size() - 1; i >= 0; i--)
		cout << "[i = " << i << "] " << words[i] << endl;
}