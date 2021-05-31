#include <iostream>
#include <vector>
#include <random> // random float
#include <iomanip> // setprecision

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
	vector<float> vec;

	for (int i = 0; i < 25; i++)
		vec.push_back(getRandomFloat());

	for (int i = 0; i < 25; i++)
		cout << setprecision(10) << vec[i] << endl;
}