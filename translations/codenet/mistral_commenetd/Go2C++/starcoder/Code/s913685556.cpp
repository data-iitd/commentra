#include <bits/stdc++.h>
using namespace std;

// The main function is the entry point of the program.
int main() {
	// Initialize a Scanner object named sc.
	Scanner sc;

	// Read two integers A and B from the standard input.
	int A, B;
	A = sc.nextInt();
	B = sc.nextInt();

	// Calculate the maximum value of A+B, A-B, and A*B using the max function.
	int mx = max(A+B, A-B);
	mx = max(mx, A*B);

	// Print the maximum value.
	cout << mx << endl;
}

