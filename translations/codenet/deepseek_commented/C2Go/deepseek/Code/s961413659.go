package main

import (
	"fmt"
)

func main() {
	var a, b int
	// Read two integers from the user input
	fmt.Scan(&a, &b)
	
	// Check if either of the integers is 1, and if so, change them to 14
	if a == 1 {
		a = 14
	}
	if b == 1 {
		b = 14
	}
	
	// Compare the two integers and print the appropriate result
	if a < b {
		fmt.Println("Bob")
	} else if a > b {
		fmt.Println("Alice")
	} else {
		fmt.Println("Draw")
	}
}

