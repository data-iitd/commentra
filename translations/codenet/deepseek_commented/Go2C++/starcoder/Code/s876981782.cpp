#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N; // Read the number of values
	vector<float> values(N);
	for (int i = 0; i < N; i++) {
		cin >> values[i]; // Read the values into the vector
	}

	sort(values.begin(), values.end()); // Sort the values in ascending order
	float generated;
	//cout << values << endl; // Uncomment to print the sorted values (for debugging purposes)
	for (int i = 0; i < N-1; i++) {
		generated = (values[i] + values[i+1]) / 2; // Calculate the average of the current and next value
		values[i+1] = generated; // Update the next value with the calculated average
	}

	cout << generated << endl; // Print the final generated value
}

