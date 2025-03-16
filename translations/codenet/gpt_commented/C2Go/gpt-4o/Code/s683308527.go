package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int // Variable to store the number of lines to read
	var s string // Variable to store each line of input

	// Read the number of lines to process
	fmt.Scanf("%d\n", &n)

	// Loop to process each line of input
	for i := 0; i < n; i++ {
		// Read a line of input from stdin
		fmt.Scanln(&s)

		// Search for the substring "Hoshino" in the input line
		// Replace the character following "Hoshino" with 'a'
		for {
			index := strings.Index(s, "Hoshino")
			if index == -1 || index+7 > len(s) {
				break
			}
			s = s[:index+6] + "a" + s[index+7:] // Replace the character after "Hoshino" with 'a'
		}

		// Print the modified line
		fmt.Println(s)
	}
}

// <END-OF-CODE>
