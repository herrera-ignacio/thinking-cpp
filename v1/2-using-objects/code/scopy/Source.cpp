#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream in("data.txt");

	ofstream out("out.txt");

	string s;

	while (getline(in, s))
		out << s << "\n";
}