package main

import (
	"fmt"
)

func main() {
	var z string // Declare a string variable to store input string
	fmt.Scan(&z) // Read input string from standard input
	a := len(z) // Calculate the size of the string and store it in a

	for i := 0; i < a-1; i++ { // Iterate through the string
		if z[i] == z[i+1] { // Check if any two consecutive characters are the same
			fmt.Println("Bad") // Print "Bad" if a pair is found and exit
			return
		}
	}
	fmt.Println("Good") // Print "Good" if no pair is found
}

// <END-OF-CODE>
