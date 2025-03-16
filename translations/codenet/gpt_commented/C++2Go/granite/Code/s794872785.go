
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize variables to track the maximum size of strings and their counts
	var maxsize int = 0 // To store the length of the longest string
	var maxcnt int = 0  // To store the count of the most frequent string
	var ans_num int // Index of the longest string
	var ans_num2 int // Index of the most frequent string
	var str_v []string // Vector to store input strings

	// Read strings from standard input until EOF
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		in := scanner.Text() // Read input string
		str_v = append(str_v, in) // Add the string to the vector
		// Check if the current string is longer than the previously recorded maximum
		if maxsize < len(in) {
			maxsize = len(in) // Update the maximum size
			ans_num = len(str_v) - 1 // Update index of the longest string
		}
	}

	// Loop through the vector to find the most frequent string
	for i := 0; i < len(str_v); i++ {
		cnt := 0 // Counter for occurrences of the current string
		// Count how many times the current string appears in the vector
		for j := 0; j < len(str_v); j++ {
			if str_v[i] == str_v[j] {
				cnt++ // Increment count if a match is found
			}
		}
		// Check if the current count is greater than the previously recorded maximum count
		if maxcnt < cnt {
			maxcnt = cnt // Update the maximum count
			ans_num2 = i // Update index of the most frequent string
		}
	}

	// Output the most frequent string and the longest string
	fmt.Println(str_v[ans_num2], str_v[ans_num])
}

