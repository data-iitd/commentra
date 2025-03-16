
#include<iostream> // Include the iostream library for input/output operations
#include<algorithm> // Include the algorithm library for standard algorithms
#include<queue> // Include the queue library for queue data structure
#include<string> // Include the string library for string manipulation
#include<vector> // Include the vector library for dynamic arrays
using namespace std; // Use the standard namespace for convenience

const int INF = 200000005; // Define a constant integer INF for use later

int main() // Begin the main function
{
	int a, b; // Declare two integer variables a and b
	cin >> a >> b; // Read the values of a and b from the standard input using cin

	// Check if both a and b are less than or equal to 8
	if (a <= 8 && b <= 8) {
		cout << "Yay!" << endl; // If the condition is true, print "Yay!" to the standard output using cout
	}
	else {
		cout << ":(" << endl; // If the condition is false, print ":(" to the standard output using cout
	}

	// End the main function and return 0 to the operating system
	return 0;
}