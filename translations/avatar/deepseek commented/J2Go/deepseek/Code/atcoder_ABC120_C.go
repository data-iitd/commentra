package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up the standard input and output streams
	reader := bufio.NewReader(os.Stdin)
	// Create a scanner to read input from the standard input stream
	scanner := bufio.NewScanner(reader)
	// Read the input string
	scanner.Scan()
	x := scanner.Text()
	// Initialize a stack to keep track of characters
	var s []rune
	// Initialize a counter to count balanced pairs
	c := 0
	// Iterate through each character in the input string
	for _, char := range x {
		// Push the current character onto the stack
		s = append(s, char)
		// While the stack has more than one element, check for balanced pairs
		for len(s) > 1 {
			// Pop the top two elements from the stack
			p := s[len(s)-1]
			s = s[:len(s)-1]
			q := s[len(s)-1]
			s = s[:len(s)-1]
			// Check if they form a balanced pair
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				// Increment the counter if a balanced pair is found
				c++
				continue
			} else {
				// If not a balanced pair, push the popped elements back onto the stack
				s = append(s, q)
				s = append(s, p)
				break
			}
		}
	}
	// Output the result, which is twice the counter value
	fmt.Println(c * 2)
}

