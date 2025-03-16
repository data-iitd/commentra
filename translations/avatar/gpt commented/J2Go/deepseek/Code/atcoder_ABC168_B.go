package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
	var input string
	fmt.Scanln(&input)
	
	// Read an integer K from the user, which represents the maximum length of the string to display
	var K int
	fmt.Sscanf(input, "%d", &K)
	
	// Read a string S from the user
	fmt.Scanln(&input)
	var S string = input
	
	// Check if the length of the string S is less than or equal to K
	if len(S) <= K {
		// If true, print the string S as it is
		fmt.Println(S)
	} else {
		// If false, print the first K characters of S followed by "..."
		fmt.Println(S[:K] + "...")
	}
}

