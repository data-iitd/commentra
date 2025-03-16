package main

import "fmt"

func main() {
	// Declare a variable to hold the input string
	var s string
	
	// Read a string input from the user
	fmt.Scan(&s)
	
	// Loop through each character in the string
	for i := 0; i < len(s); i++ {
		// Print 'x' for each character in the input string
		fmt.Print("x")
	}
	
	// Print a newline after printing all 'x's
	fmt.Println("")
}
