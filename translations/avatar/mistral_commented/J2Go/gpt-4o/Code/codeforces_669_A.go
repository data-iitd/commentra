package main

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() {
	var n int // Declare an integer variable 'n' to store the input number

	// Read the input number from the console and store it in the 'n' variable
	fmt.Print("Enter a number: ")
	fmt.Scan(&n)

	// Call the 'solve' function to calculate and print the result
	solve(n)
}

// 'solve' function to calculate and print the result
func solve(n int) {
	// Calculate the result and print it to the console
	fmt.Println((n/3)*2 + func() int {
		if n%3 == 0 {
			return 0
		}
		return 1
	}())
}

// <END-OF-CODE>
