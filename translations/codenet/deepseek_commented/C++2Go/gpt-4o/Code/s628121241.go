package main

import (
	"fmt"
)

// Function to calculate the greatest common divisor (GCD) using recursion
func gcd(a, b int) int {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func main() {
	// Take an integer input from the user
	var R int
	fmt.Scan(&R)

	// Check the value of R and print the corresponding output
	if R < 1200 {
		fmt.Println("ABC") // If R is less than 1200, print "ABC"
	} else if R >= 2800 {
		fmt.Println("AGC") // If R is 2800 or more, print "AGC"
	} else {
		fmt.Println("ARC") // Otherwise, print "ARC"
	}
}

// <END-OF-CODE>
