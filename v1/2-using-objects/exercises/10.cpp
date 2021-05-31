#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

constexpr int FLOAT_MIN = 1;
constexpr int FLOAT_MAX = 100;

float getRandomFloat() {
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<> distr(FLOAT_MIN, FLOAT_MAX);

	return distr(eng);
}

int main() {
	vector<float> v;

	// Populate vector
	for (int i = 0; i < 25; i++) {
		v.push_back(getRandomFloat());
	}

	// Print before multiplication
	cout << "Before: ";

	for (auto x : v)
		cout << setprecision(10) << x << " ";

	// Square each number
	for (int j = 0; j < 25; j++)
		v[j] = v[j] * v[j];

	// Print after multiplication
	cout << "\nAfter: ";

	for (auto y : v)
		cout << setprecision(10) << y << " ";
}