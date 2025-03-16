
package main

import (
	"fmt"
	"sort"
	"strings"
)

// Function main is the entry point of the program
func main() {
	// Initialize an empty string variable 's' to store the input DNA sequence
	var s string

	// Read the input DNA sequence from the standard input using fmt.Scan() function
	fmt.Scan(&s)

	// Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
	// and a slice 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
	count := 0
	var counter []int

	// Check if the input DNA sequence is empty or not
	if s == "" {
		// If the input DNA sequence is empty, return without doing anything
		return
	}

	// Initialize the first element of the 'counter' slice with an initial count of 0
	counter = append(counter, 0)

	// Split the input DNA sequence into a slice 'li' of individual nucleotides using strings.Split() function
	li := strings.Split(s, "")

	// Iterate through each nucleotide in the 'li' slice using a for loop
	for _, s := range li {
		// Check if the current nucleotide is a valid nucleotide (A, C, G, T) or not
		if s == "A" || s == "C" || s == "G" || s == "T" {
			// If the current nucleotide is a valid nucleotide, increment the 'count' variable
			count++
		} else {
			// If the current nucleotide is not a valid nucleotide, append the current count to the 'counter' slice and reset the 'count' variable to 0
			counter = append(counter, count)
			count = 0
		}
	}

	// Append the final count of nucleotides in the last sub-sequence to the 'counter' slice
	counter = append(counter, count)

	// Sort the 'counter' slice in ascending order using sort.Ints() function
	sort.Ints(counter)

	// Print the last element of the sorted 'counter' slice, which represents the maximum count of nucleotides in any sub-sequence
	fmt.Println(counter[len(counter)-1])
}

