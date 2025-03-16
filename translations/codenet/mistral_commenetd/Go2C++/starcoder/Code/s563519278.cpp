
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	// Read the number of elements from the standard input
	int N;
	cin >> N;

	// Initialize a vector 'v' of size N to store the frequency of each element
	vector<int> v(N);

	// Iterate through the input elements and update the frequency in the vector 'v'
	for (int i = 1; i < N; i++) {
		// Read the next element from the standard input
		string s;
		cin >> s;
		// Convert the string to integer 'a'
		int a;
		stringstream(s) >> a;
		// Update the frequency of the element 'a-1' in the vector 'v'
		v[a-1]++;
	}

	// Iterate through the vector 'v' and print each element to the standard output
	for (int e : v) {
		// Print each element to the standard output
		cout << e << endl;
	}

	// End of the code
}

