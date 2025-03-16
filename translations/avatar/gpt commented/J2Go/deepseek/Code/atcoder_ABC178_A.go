package main

import (
	"fmt"
)

func main() {
	// Reading an integer input from the user
	var x int
	fmt.Scan(&x)
	
	// Using a ternary operator to determine the boolean value based on the input
	bool := x == 1
	
	// Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
	result := 0
	if bool {
		result = 1
	}
	
	// Printing the result to the console
	fmt.Println(result)
}
