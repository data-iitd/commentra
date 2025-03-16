
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the input string
	x, _ := reader.ReadString('\n')
	x = strings.TrimSpace(x)

	s := []rune(x)
	c := 0 // Counter for pairs of '0' and '1'

	// Iterate through each character in the input string
	for i := 0; i < len(s); i++ {
		// Push the current character onto the stack
		s = append(s, s[i])

		// Process the stack while there are at least two characters
		for len(s) > 1 {
			p := s[len(s)-1] // Pop the top character
			s = s[:len(s)-1]
			q := s[len(s)-1] // Pop the next character
			s = s[:len(s)-1]

			// Check if the characters form a pair of '0' and '1'
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++ // Increment the counter for valid pairs
				continue // Continue to check for more pairs
			} else {
				// If not a valid pair, push the characters back onto the stack
				s = append(s, q)
				s = append(s, p)
				break // Exit the while loop
			}
		}
	}

	// Output the result, which is twice the count of pairs found
	fmt.Fprintln(writer, c*2)

	// Close the output stream
	writer.Flush()
}

// END-OF-CODE