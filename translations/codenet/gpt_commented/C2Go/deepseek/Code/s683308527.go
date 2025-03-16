package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int
	var s string
	var c *string

	// Read the number of lines to process
	fmt.Scan(&n)

	// Create a scanner to read input line by line
	scanner := bufio.NewScanner(os.Stdin)

	// Loop to process each line of input
	for i := 0; i < n; i++ {
		// Read a line of input from stdin
		scanner.Scan()
		s = scanner.Text()

		// Search for the substring "Hoshino" in the input line
		// Replace the character following "Hoshino" with 'a'
		for strings.Contains(s, "Hoshino") {
			c = strings.Index(s, "Hoshino")
			if c != -1 {
				s = s[:c+6] + "a" + s[c+7:]
			}
		}

		// Print the modified line
		fmt.Println(s)
	}
}

