package main

import (
	"fmt"
)

func main() {
	var k, a, b int64 // Initialize variables a, b, and k
	fmt.Scan(&k, &a, &b) // Read input values for k, a, and b

	// Check if there exists an integer between a and b that is divisible by k
	for i := a; i <= b; i++ {
		if i%k == 0 { // If current number is divisible by k
			fmt.Println("OK") // Print "OK" and exit the program
			return // Exit the program with success status
		}
	}

	fmt.Println("NG") // If no number between a and b is divisible by k, print "NG"
}

// <END-OF-CODE>
