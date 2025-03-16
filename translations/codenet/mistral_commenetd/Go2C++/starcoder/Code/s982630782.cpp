
#include <bits/stdc++.h>

using namespace std;

int main() {
	// Initialize an empty map to store the frequency of each number
	map<int, int> m;

	// Read the number of test cases N
	int N = ReadInt();
	// Read the N integers and store their frequencies in the map
	for (int i = 0; i < N; i++) {
		int num = ReadInt();
		m[num]++;
	}

	// Read the number of queries M
	int M = ReadInt();
	// For each query, read the number B and the index C, and update the frequency of the number at index C in the map
	for (int i = 0; i < M; i++) {
		int B, C = ReadInt(), ReadInt();
		m[C] += B;
	}

	// Create a vector of integers from the map keys
	vector<int> ints(m.size());
	int i = 0;
	// Populate the vector with the map keys
	for (auto it = m.begin(); it!= m.end(); it++) {
		ints[i] = it->first;
		i++;
	}

	// Sort the vector in descending order
	sort(ints.begin(), ints.end(), greater<int>());

	// Initialize variables for calculating the sum
	int rest = N;
	int sum = 0;
	// Iterate through the sorted vector of integers
	for (int i = 0; i < ints.size(); i++) {
		int num = m[ints[i]];
		// If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
		if (num >= rest) {
			sum += rest * ints[i];
			break;
		}
		// Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
		sum += num * ints[i];
		rest -= num;
	}

	// Print the result
	cout << sum << endl;
}

int ReadInt() {
	int i;
	cin >> i;
	return i;
}

