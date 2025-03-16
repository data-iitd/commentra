package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize an empty list to store the sequence
	L := []int{}

	// Initialize a variable 'r' to keep track of the current number to be added to the list
	r := 1

	// Create a new scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Read a line of input, split it into parts, and iterate over each part
	scanner.Scan()
	for _, k := range strings.Split(scanner.Text(), " ") {
		// Convert the part to an integer
		num, _ := strconv.Atoi(k)
		// Extend the list 'L' by adding 'r' for 'num' times
		for i := 0; i < num; i++ {
			L = append(L, r)
		}
		// Increment 'r' for the next number
		r += 1
	}

	// Read another line of input (not used, but could be for prompting the user)
	scanner.Scan()

	// Read a line of input, split it into parts, and iterate over each part
	scanner.Scan()
	for _, j := range strings.Split(scanner.Text(), " ") {
		// Convert the part to an integer
		index, _ := strconv.Atoi(j)
		// Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
		fmt.Println(L[index-1])
	}
}

