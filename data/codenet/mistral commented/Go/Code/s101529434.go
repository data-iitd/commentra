
package main

import "fmt"

func main() {
	// Declare two integer variables, K and X
	var K, X int

	// Read two integers from the standard input and assign them to the variables K and X respectively
	fmt.Scan(&K, &X)

	// Check if the condition 500*K >= X is true
	if 500*K >= X {
		// If the condition is true, print the string "Yes" to the standard output
		fmt.Println("Yes")
	} else {
		// If the condition is false, print the string "No" to the standard output
		fmt.Println("No")
	}
}

