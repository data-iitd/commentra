package main

import (
	"fmt"
)

func main() {
	// Declare an integer variable to store the input value.
	var x int
	
	// Read an integer input from the user and store it in the variable x.
	fmt.Scan(&x)
	
	// Check the value of x and print 1 or 0 based on the value of x.
	if x == 0 {
		fmt.Println("1")
	}
	if x == 1 {
		fmt.Println("0")
	}
}

