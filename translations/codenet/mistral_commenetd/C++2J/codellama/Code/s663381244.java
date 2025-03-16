// Initialize cin and ios streams to disable buffering and synchronization
System.setIn(new BufferedInputStream(System.in));

// Initialize an empty vector 'm' to store the multipliers
ArrayList<Integer> m = new ArrayList<Integer>();

// Push back the multipliers into the vector 'm'
m.add(10);
m.add(50);
m.add(100);
m.add(500);

boolean first = true; // Initialize a boolean variable 'first' to check if it's the first iteration of the loop

// Main loop to read the input money and calculate the change
while(true) {
	// If it's not the first iteration, print a newline character to separate the outputs
	if(!first)
		System.out.println();

	// Set 'first' to false
	first = false;

	// Initialize variables 'sum' and 'num'
	int sum = 0;
	ArrayList<Integer> num = new ArrayList<Integer>();

	// Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
	for(int i = 0; i < 4; ++i) {
		num.add(i, Integer.parseInt(System.console().readLine())); // Read the number
		sum += num.get(i) * m.get(i); // Calculate the product and add it to the sum
	}

	// Calculate the change
	int change = sum - Integer.parseInt(System.console().readLine());

	// Adjust the numbers to get the exact change
	for(int i = 3; i >= 0; --i) {
		// If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
		if(change / m.get(i)) {
			num.set(i, num.get(i) - change / m.get(i));
			change %= m.get(i);
		}
	}

	// Print the numbers that still have a positive value
	for(int i = 0; i < 4; ++i)
		if(num.get(i) > 0)
			System.out.println(m.get(i) + " " + num.get(i));
}

// Return EXIT_SUCCESS to indicate successful execution
System.exit(0);
