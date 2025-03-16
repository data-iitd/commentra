package main

import "fmt"

func main() {
	// Read an integer input from the user, which represents the number of test cases
	var n int
	fmt.Scan(&n)

	// Loop through each test case
	for i := 0; i < n; i++ {
		// Read an integer input for the current test case
		var a int
		fmt.Scan(&a)

		// Check if the input number is less than 2
		if a < 2 {
			// If true, print 0 as the output for this case
			fmt.Println(0)
		}

		// Check if the input number is greater than or equal to 2
		if a >= 2 {
			// If true, print the result of (a - 2)
			fmt.Println(a - 2)
		}
	}
}

