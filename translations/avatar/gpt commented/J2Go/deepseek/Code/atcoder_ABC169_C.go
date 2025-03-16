package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the user
	var a int64
	var b string
	
	// Read a long integer value from the user
	fmt.Scan(&a)
	
	// Read a string value from the user
	fmt.Scan(&b)
	
	// Convert the string to a character array for processing
	bChars := []rune(b)
	
	// Initialize an empty string to build the integer representation
	var bStr string
	
	// Loop through each character in the character array
	for _, char := range bChars {
		// If the character is not a '.', append it to bStr
		if char != '.' {
			bStr += string(char)
		}
	}
	
	// Convert the built string (bStr) to an integer
	bInt, _ := strconv.Atoi(bStr)
	
	// Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
	result := (a * int64(bInt)) / 100
	
	// Print the result to the console
	fmt.Println(result)
}
