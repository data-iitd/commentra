package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold input values
	var a, b, c, d, e, k int

	// Read six integers from standard input
	fmt.Scan(&a, &b, &c, &d, &e, &k)

	// Check if the difference between e and a is less than or equal to k
	// If true, print "Yay!", otherwise print ":("
	if e - a <= k {
		fmt.Println("Yay!")
	} else {
		fmt.Println(":(")
	}
}

