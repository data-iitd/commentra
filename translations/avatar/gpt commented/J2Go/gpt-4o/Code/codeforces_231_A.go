package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t) // Reading the number of test cases
	count := 0   // Initializing a counter to keep track of valid cases

	// Looping through each test case
	for t > 0 {
		t-- // Decrementing the test case counter
		var a, b, c int
		fmt.Scan(&a, &b, &c) // Reading the three integers

		// Checking if at least one of the integers is equal to 1
		if (a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1) {
			count++ // Incrementing the count if the condition is met
		}
	}

	// Outputting the total count of valid cases
	fmt.Println(count)
}

// <END-OF-CODE>
