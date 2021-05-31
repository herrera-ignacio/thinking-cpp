#include <iostream>
#include <cmath>

using namespace std;

const long double PI = 3.141592653589793238L;

int main() {
	int radius;

	cout << "Input circle's radius:" << endl;
	cin >> radius;

	double area;
	area = PI * pow(radius, 2);
	cout << "Circle area: " << area << endl;
}