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
	vector<float> v1;
	vector<float> v2;
	vector<float> v3;

	for (int i = 0; i < 25; i++)
		v1.push_back(getRandomFloat());

	for (int j = 0; j < 25; j++)
		v2.push_back(getRandomFloat());

	for (int k = 0; k < 25; k++)
		v3.push_back(v1[k] + v2[k]);

	for (auto x : v3)
		cout << setprecision(10) << x << endl;
}