package main

import (
	"fmt"
)

// Function to generate a character array from the concatenation of numbers 1 to 1000
func generateString() []rune {
	var sb []rune // Creating a slice to efficiently build the string
	
	// Looping through numbers 1 to 1000 and appending them to the slice
	for i := 1; i <= 1000; i++ {
		for _, digit := range fmt.Sprintf("%d", i) { // Appending the current number to the slice
			sb = append(sb, digit)
		}
	}
	
	// Returning the built slice as a character array
	return sb
}

func main() {
	// Reading an integer input from the user
	var n int
	fmt.Scan(&n)
	
	// Printing the character at the (n-1)th index of the generated character array
	charArray := generateString()
	fmt.Println(string(charArray[n - 1]))
}

