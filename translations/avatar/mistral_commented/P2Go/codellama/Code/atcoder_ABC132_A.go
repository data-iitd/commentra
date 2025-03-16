package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take a string as input from the user
	var S string
	fmt.Scanln(&S)

	// Import the Counter function from the collections module to count the frequency of each character in the string
	// Create a set Sa from the list of characters in the string S
	Sa := make(map[string]int)
	for _, v := range S {
		Sa[string(v)]++
	}

	// Check if the length of the set Sa is equal to 2
	if len(Sa) != 2 {
		// If not, print "No" and exit the program
		fmt.Println("No")
		return
	}

	// Iterate through each character i in the set Sa
	for i := range Sa {
		// For each character i, check if its frequency in the string S is equal to 2 using the Counter dictionary c
		if Sa[i] != 2 {
			// If the frequency of any character is not equal to 2, print "No" and exit the program
			fmt.Println("No")
			return
		}
	}

	// If all characters have a frequency of 2, print "Yes" to indicate that the string satisfies the condition
	fmt.Println("Yes")
}

