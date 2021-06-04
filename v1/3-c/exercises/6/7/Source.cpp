#include <iostream>

void mutate_string_1(std::string* s) {
	*s = "Mutated by pointer dereference";
}

void mutate_string_2(std::string &s) {
	s = "Mutated by address reference";
}

int main() {
	std::string s = "demo";

	std::cout << "(s) initial value: " << s << std::endl;

	mutate_string_1(&s);

	std::cout << "(s) after mutate_string_1: " << s << std::endl;

	mutate_string_2(s);

	std::cout << "(s) after mutate_string_2: " << s << std::endl;
}