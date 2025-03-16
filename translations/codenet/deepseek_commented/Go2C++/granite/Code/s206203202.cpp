

#include <iostream>
#include <cmath>

using namespace std;

// Abs returns the absolute value of an integer
int Abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// min returns the smaller of two integers
int min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int main() {
	int N, K;
	cin >> N >> K; // Read two integers from input

	int x = N % K; // Calculate the remainder of N divided by K

	x = min(Abs(x-K), x); // Calculate the minimum of the absolute difference and x itself
	cout << x << endl; // Print the result
}



Translate the above Go code to Java and end with comment "