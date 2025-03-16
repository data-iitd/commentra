
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

// Main function of the program
int main() {
	// Read two integers A and B from standard input
	int A, B;
	cin >> A >> B;

	// Check if the sum of A and B is even
	if ((A+B)%2 == 0) {
		// If even, print the average of A and B
		cout << (A + B) / 2 << endl;
		return 0;
	}
	// If not even, print "IMPOSSIBLE"
	cout << "IMPOSSIBLE" << endl;
	return 0;
}

