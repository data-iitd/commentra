package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Initialize an empty slice to store the sequence
	var L []int

	// Read input (not used, but could be for prompting the user)
	var input string
	fmt.Scanln(&input)

	// Initialize a variable 'r' to keep track of the current number to be added to the slice
	r := 1

	// Read a line of input, split it into parts, and iterate over each part
	fmt.Scanln(&input)
	for _, k := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(k)
		// Extend the slice 'L' by adding 'r' for 'num' times
		for i := 0; i < num; i++ {
			L = append(L, r)
		}
		// Increment 'r' for the next number
		r++
	}

	// Read another line of input (not used, but could be for prompting the user)
	fmt.Scanln(&input)

	// Read a line of input, split it into parts, and iterate over each part
	fmt.Scanln(&input)
	for _, j := range strings.Split(input, " ") {
		index, _ := strconv.Atoi(j)
		// Print the element from slice 'L' at the index specified by 'j' (adjusted for 0-based index)
		fmt.Println(L[index-1])
	}
}

// <END-OF-CODE>
