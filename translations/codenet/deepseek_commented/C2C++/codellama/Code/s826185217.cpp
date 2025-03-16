#include <iostream> // Step 1: Include the standard input/output library to use cin and cout functions.

using namespace std; // Step 2: Use the namespace std to use the cin and cout functions.

int main(void){ // Step 3: Define the main function where the execution of the program begins.
	int a, b, c, d; // Step 4: Declare four integer variables a, b, c, and d to store the input values.

	cin >> a >> b >> c >> d; // Step 5: Use cin function to read four integers from the user and store them in variables a, b, c, and d.

	if (a + b > c + d) // Step 6: Compare the sum of a and b with the sum of c and d.
		cout << "Left\n"; // Step 7: If the sum of a and b is greater than the sum of c and d, print "Left".
	else if (a + b < c + d) // Step 8: If the sum of a and b is less than the sum of c and d, print "Right".
		cout << "Right\n";
	else // Step 9: If the sums are equal, print "Balanced".
		cout << "Balanced\n";

	return 0; // Step 10: Return 0 to indicate successful execution of the program.
}

