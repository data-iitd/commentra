package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of strings to be processed
	var n int
	fmt.Fscan(reader, &n)

	// Initialize a map to count occurrences of each string
	s := make(map[string]int)

	// Read n strings into a slice
	l := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &l[i])
	}

	// Initialize a flag to determine if the conditions are met
	f := "Yes"

	// Iterate through each string in the slice
	for _, v := range l {
		// Increment the count for the current string
		s[v]++

		// Check if the current string has appeared more than once
		if s[v] >= 2 {
			f = "No" // Set flag to "No" if a duplicate is found
		}

		// Check if the previous string's last character does not match the current string's first character
		if len(l) > 1 && l[len(l)-1] != v[0] {
			f = "No" // Set flag to "No" if the character condition is violated
		}
	}

	// Print the final result based on the checks
	fmt.Fprintln(writer, f)
}

