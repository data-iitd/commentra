package main

import "fmt"

// Initialize an empty string variable named 's'
var s string

// Read a string input from the user using fmt.Scan() function
fmt.Scan(&s)

// Declare a variable named 'price' with initial value 700
price := 700

// Iterate through each character 'c' in the string 's' using a for loop
for _, c := range s {
	// Check if the current character 'c' is equal to 'o'
	if c == 'o' {
		// If yes, add 100 to the 'price' variable
		price += 100
	}
}

// Print the final value of 'price' using fmt.Println() function
fmt.Println(price)
