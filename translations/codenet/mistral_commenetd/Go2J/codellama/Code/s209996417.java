// This is the main function where the program starts execution
public static void main(String[] args) {
	// Initialize two double variables n and k to read input values
	double n;
	double k;

	// Read input values n and k from the standard input using Scanner class
	Scanner scanner = new Scanner(System.in);
	n = scanner.nextDouble();
	k = scanner.nextDouble();

	// Calculate the number of digits required in k-base representation of number n
	// This is done by finding the smallest power of k such that k^x <= n and n < k^(x+1)

	// Initialize a double variable x with initial value 0.0
	double x = 0.0;

	// Use a for loop to find the smallest power of k that satisfies the condition
	for (;;) {
		// Calculate the lower and upper bounds of the current power of k
		double under = Math.pow(k, x);
		double upper = Math.pow(k, x + 1);

		// Check if the number n lies between under and upper bounds
		if (under <= n && n < upper) {
			// If the condition is satisfied, print the result (number of digits) and exit the function
			System.out.println(x + 1);
			return;
		}

		// If the condition is not satisfied, increment the value of x and continue the loop
		x++;
	}
}

// 