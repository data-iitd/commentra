package main

import "fmt"

func main() {
	// Declare a variable to hold the input string
	var n string
	
	// Read input from the user and store it in variable n
	fmt.Scan(&n)
	
	// Loop through the first three characters of the input string
	for i := 0; i < 3; i++ {
		// Check if the current character is '7'
		if n[i] == '7' {
			// If '7' is found, print "Yes" and exit the program
			fmt.Println("Yes")
			return
		}
	}
	
	// If '7' is not found in the first three characters, print "No"
	fmt.Println("No")
}
