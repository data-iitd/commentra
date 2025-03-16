
// This is the main function where the program starts execution
int main() {
	// Initialize two float64 variables n and k to read input values
	float64 n, k;

	// Read input values n and k from the standard input using cin >> n >> k
	cin >> n >> k;

	// Calculate the number of digits required in k-base representation of number n
	// This is done by finding the smallest power of k such that k^x <= n and n < k^(x+1)

	// Initialize a float64 variable x with initial value 0.0
	float64 x = 0.0;

	// Use a for loop to find the smallest power of k that satisfies the condition
	for(; ; ) {
		// Calculate the lower and upper bounds of the current power of k
		float64 under = pow(k, x);
		float64 upper = pow(k, x+1);

		// Check if the number n lies between under and upper bounds
		if(under <= n && n < upper) {
			// If the condition is satisfied, print the result (number of digits) and exit the function
			cout << x + 1 << endl;
			return 0;
		}

		// If the condition is not satisfied, increment the value of x and continue the loop
		x++;
	}
}

// "

Translate the above C++ code to Python and end with comment "