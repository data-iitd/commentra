package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t) // Step 4: Read the number of test cases
	count := 0 // Step 6: Initialize a counter to keep track of the number of times the condition is met

	// Step 7: Use a for loop to iterate through each test case
	for i := 0; i < t; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c) // Step 8: Read the values of a, b, and c for each test case

		// Step 9: Check if any of the values are 1 or if all three values are 1
		if a == 1 && b == 1 || a == 1 && c == 1 || b == 1 && c == 1 || a == 1 && b == 1 && c == 1 {
			count++ // Step 10: Increment the counter if the condition is met
		}
	}

	// Step 11: Print the counter value after the loop
	fmt.Println(count)
}
