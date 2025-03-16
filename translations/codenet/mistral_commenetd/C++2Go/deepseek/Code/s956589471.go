package main

import (
	"fmt"
)

func main() {
	var a, b, c, d, e, k int

	// Read the values of these variables from the standard input using fmt.Scan
	fmt.Scan(&a, &b, &c, &d, &e, &k)

	// Perform a simple condition check using the relational operator <=
	if e - a <= k {
		fmt.Println("Yay!") // If the condition is true, print "Yay!" to the standard output
	} else {
		fmt.Println(":(") // If the condition is false, print ":" and a sad face "(" to the standard output
	}
}

