
#include <iostream> // Include the standard input-output library
using namespace std;

// Define two integer variables: N and A
int N, A;

int main() {
	// Read the values of N and A from the standard input
	cin >> N >> A;

	// Use the conditional operator to check if the remainder of N divided by 500 is less than or equal to A
	cout << (N % 500 <= A ? "Yes" : "No") << endl;

	// End the main function and return 0 to indicate successful execution
	return 0;
}