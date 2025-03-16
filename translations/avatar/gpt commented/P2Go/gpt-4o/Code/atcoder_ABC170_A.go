package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input
	var input string
	fmt.Scanln(&input)

	// Split the input into components and convert each component to an integer
	components := strings.Split(input, " ")
	var a []int
	for _, component := range components {
		num, _ := strconv.Atoi(component)
		a = append(a, num)
	}

	// Iterate over the slice 'a' using a for loop with index
	for e, i := range a {
		// Check if the current value is zero
		if i == 0 {
			// Print the index (1-based) of the first occurrence of zero
			fmt.Println(e + 1)
			// Exit the loop after finding the first zero
			break
		}
	}
}

// <END-OF-CODE>
