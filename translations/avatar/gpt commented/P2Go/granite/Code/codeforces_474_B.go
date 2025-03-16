
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize an empty slice to store the sequence
	L := make([]int, 0)

	// Read input (not used, but could be for prompting the user)
	bufio.NewReader(os.Stdin).ReadBytes('\n')

	// Initialize a variable 'r' to keep track of the current number to be added to the slice
	r := 1

	// Read a line of input, split it into parts, and iterate over each part
	for _, k := range bufio.NewReader(os.Stdin).ReadBytes('\n') {
		// Extend the slice 'L' by adding 'r' for 'int(k)' times
		L = append(L, r)
		// Increment 'r' for the next number
		r++
	}

	// Read another line of input (not used, but could be for prompting the user)
	bufio.NewReader(os.Stdin).ReadBytes('\n')

	// Read a line of input, split it into parts, and iterate over each part
	for _, j := range bufio.NewReader(os.Stdin).ReadBytes('\n') {
		// Print the element from slice 'L' at the index specified by 'j' (adjusted for 0-based index)
		fmt.Println(L[strconv.Atoi(string(j))-1])
	}
}
