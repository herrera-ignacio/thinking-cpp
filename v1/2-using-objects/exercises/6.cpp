#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	vector<string> words;
	ifstream in("GetWords.cpp");
	string word;
	string buffer;

	while (in >> word)
		words.push_back(word);

	for (int i = 0; i < words.size(); i++)
		buffer += words[i];

	cout << buffer;
}