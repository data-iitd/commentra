package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Create a Scanner object for reading input
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	// Read the input string and replace occurrences of "BC" with "D"
	var s string
	if scanner.Scan() {
		s = scanner.Text()
	}
	s = replaceAll(s, "BC", "D")

	// Initialize counters for 'A' and the result
	var cnt, tmp int64

	// Iterate through the modified string to count occurrences
	for _, char := range s {
		// Increment temporary counter for 'A'
		if char == 'A' {
			tmp++
		}
		// Add the count of 'A's to the result when 'D' is encountered
		else if char == 'D' {
			cnt += tmp
		}
		// Reset the temporary counter for any other character
		else {
			tmp = 0
		}
	}

	// Output the final count of valid pairs
	fmt.Fprintln(writer, cnt)
}

// Helper function to replace all occurrences of a substring with another string
func replaceAll(s, old, new string) string {
	return ""
}
