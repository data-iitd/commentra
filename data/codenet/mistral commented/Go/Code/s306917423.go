package main

import (
	"fmt" // Importing the 'fmt' package for input/output operations
)

func main() {
	// Declaring a variable 's' of type 'string' to store the input string
	var s string

	// Reading the string input using 'fmt.Scan' function
	fmt.Scan(&s)

	// Declaring a variable 'ans' of type 'int' to store the answer
	var ans int

	// Initializing the answer to zero
	ans = 0

	// Looping through each character 'c' in the string 's'
	for _, c := range s {
		// Checking if the current character 'c' is equal to '1'
		if c == '1' {
			// Incrementing the answer if the character is '1'
			ans++
		}
	}

	// Printing the answer using 'fmt.Println' function
	fmt.Println(ans)

	// End of the code
}