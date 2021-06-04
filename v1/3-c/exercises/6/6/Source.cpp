/**
Modify YourPets2.cpp so that it uses various different data types
(char, int, float, double, and their variants). Run the program
and create a map of the resulting memory layout
**/

#include <iostream>

char c;
int i;
float f;
double d;

void func(int i) {
	std::cout << "func's int i: " << i << std::endl;
}

int main() {
	long int li;
	short int si;
	long double ld;

	std::cout << "&func(): " << (long)&func << std::endl;
	std::cout << "&c: " << (long)&c << std::endl;
	std::cout << "&i: " << (long)&i << std::endl;
	std::cout << "&f: " << (long)&f << std::endl;
	std::cout << "&d: " << (long)&d << std::endl;
	std::cout << "&li: " << (long)&li << std::endl;
	std::cout << "&si: " << (long)&si << std::endl;
	std::cout << "&ld: " << (long)&ld << std::endl;
}
