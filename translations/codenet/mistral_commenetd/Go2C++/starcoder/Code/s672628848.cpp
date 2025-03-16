#include <iostream>
#include <vector>

using namespace std;

int main() {
	// Declare variables a, b, c, d, and e of type int
	int a, b, c, d, e;

	// Read input values for variables a, b, c, d, and e from the standard input
	cin >> a >> b >> c >> d >> e;

	// Create a vector named al with the values of variables a, b, c, d, and e
	vector<int> al = {a, b, c, d, e};

	// Iterate through each element i in the vector al starting from the index 0
	for (int n = 0; n < al.size(); n++) {
		// Assign the index number n and the current element i to the variables n and i respectively
		// Check if the current element i is equal to 0
		if (al[n] == 0) {
			// Print the index number n+1 as output
			cout << n + 1 << endl;
			// Break the loop as soon as the first zero element is found
			break;
		}
	}

	return 0;
}

