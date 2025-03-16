package main

import (
	"fmt"
)

func main() {
	var x int

	// Read an integer value from user input and store it in x
	fmt.Scan(&x)

	// Check if the value of x is equal to 1
	if x == 1 {
		fmt.Println("0") // If x is 1, print "0"
	} else {
		fmt.Println("1") // If x is not 1, print "1"
	}
}

