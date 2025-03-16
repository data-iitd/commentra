package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s) // Read the input string.
	s = strings.ReplaceAll(s, "BC", "D") // Replace all occurrences of "BC" with "D".
	
	cnt := int64(0) // Initialize a counter to keep track of the result.
	tmp := int64(0) // Temporary variable to count consecutive 'A's.
	
	for _, char := range s {
		if char == 'A' {
			tmp++ // Increment tmp if the current character is 'A'.
		} else if char == 'D' {
			cnt += tmp // Add tmp to cnt if the current character is 'D'.
		} else {
			tmp = 0 // Reset tmp if the current character is not 'A' or 'D'.
		}
	}
	
	fmt.Println(cnt) // Print the final count.
}

// The main function contains the logic to solve the problem.
