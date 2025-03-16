package main

import (
	"fmt"
)

func main() {
	var N, X int64 // Declare variables to store the number of elements and the target value
	fmt.Scan(&N, &X) // Read the values of N and X from the standard input

	ans := int64(0) // Initialize the answer variable
	min := int64(1000000000) // Initialize the minimum value variable

	for i := int64(0); i < N; i++ { // Loop through N elements
		var tmp int64 // Declare a temporary variable to store each input value
		fmt.Scan(&tmp) // Read the value into the temporary variable
		X -= tmp // Subtract the value from X
		ans++ // Increment the answer count
		if tmp < min { // Update the minimum value if the current value is smaller
			min = tmp
		}
	}

	ans += X / min // Calculate the final answer by adding the quotient of X divided by the minimum value

	fmt.Println(ans) // Print the final answer to the standard output
}

// <END-OF-CODE>
