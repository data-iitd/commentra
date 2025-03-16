package main

import "fmt"

func main() {
	// Declare a variable to hold the input string
	var s string
	
	// Read input from the user and store it in the variable 's'
	fmt.Scan(&s)

	// Initialize the base price
	price := 700
	
	// Iterate over each character in the input string
	for _, c := range s {
		// Check if the character is 'o'
		if c == 'o' {
			// If it is 'o', increase the price by 100
			price += 100
		}
	}
	
	// Print the final price after processing the input string
	fmt.Println(price)
}
