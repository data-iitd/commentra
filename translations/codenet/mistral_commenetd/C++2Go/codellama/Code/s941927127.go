
package main

import (
	"fmt"
	"sort"
)

func main() {
	var W string // Declare a string variable named W to store the input word

	// Read the input word from the standard input stream using fmt.Scan
	fmt.Scan(&W)

	// Sort the characters in the string W in ascending order using the sort function from the sort package
	sort.Slice(W, func(i, j int) bool {
		return W[i] < W[j]
	})

	// Initialize a string iterator named itr to point to the first character in the sorted string W
	itr := 0

	// Loop through the sorted string W using a for loop, with the loop condition that itr does not point to the end of the string
	for itr < len(W) {
		// Check if the current character and the next character in the string are the same
		if W[itr] != W[itr+1] {
			// If they are not the same, print "No" to the standard output stream and return from the main function
			fmt.Println("No")
			return
		}
		itr++
	}

	// If the loop completes without finding any pair of non-identical characters, print "Yes" to the standard output stream
	fmt.Println("Yes")

	// Return 0 to indicate successful execution of the main function
	return
}

