package main

import "fmt"

func main() {
	// Declare a variable 'n' of type string
	var n string

	// Read a string input from the user using fmt.Scan()
	fmt.Scan(&n)

	// Initialize a loop counter 'i'
	for i := 0; i < 3; i++ {
		// Check if the current character in the string 'n' is equal to '7'
		if n[i] == '7' {
			// If yes, print "Yes" and exit the function
			fmt.Println("Yes")
			return
		}
	}

	// If no '7' is found in the first three characters, print "No"
	fmt.Println("No")
}