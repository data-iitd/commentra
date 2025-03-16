#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Create a vector to hold three integers
	vector<int> in;

	// Read three integers from standard input
	for (int i = 0; i < 3; i++) {
		int n;
		cin >> n;
		in.push_back(n);
	}

	// Sort the integers in ascending order
	sort(in.begin(), in.end());

	// Calculate the result based on the sorted integers
	// The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
	cout << in[2]*10 + in[1] + in[0] << endl;
}

