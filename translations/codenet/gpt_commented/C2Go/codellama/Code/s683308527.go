package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int // Variable to store the number of lines to read
	var s string // Array to store each line of input
	var c int // Pointer to search for the substring "Hoshino"

	// Read the number of lines to process, ignoring the newline character
	fmt.Scan(&n)

	// Loop to process each line of input
	for n > 0 {
		// Read a line of input from stdin
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Scan()
		s = scanner.Text()

		// Search for the substring "Hoshino" in the input line
		// Replace the character following "Hoshino" with 'a'
		for c = strings.Index(s, "Hoshino"); c != -1; c = strings.Index(s, "Hoshino") {
			s = s[:c+6] + "a" + s[c+7:]
		}

		// Print the modified line
		fmt.Println(s)

		n--
	}
}

