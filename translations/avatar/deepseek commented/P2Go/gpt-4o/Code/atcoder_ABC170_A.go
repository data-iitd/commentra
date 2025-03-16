package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input) // Take input from user

	// Split the input string into a slice of strings
	strSlice := strings.Split(input, " ")
	a := make([]int, len(strSlice))

	// Convert the slice of strings to a slice of integers
	for i, s := range strSlice {
		fmt.Sscanf(s, "%d", &a[i])
	}

	// Iterate over the slice, checking each element
	for e, i := range a {
		if i == 0 { // If an element is 0
			fmt.Println(e + 1) // Print the position (1-indexed) of that element
			break
		}
	}
}

// <END-OF-CODE>
