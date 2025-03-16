
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var x string // String to store the input string
	var s []string // Stack to store characters
	var c int // Counter to store the number of pairs

	x = readLine() // Reading the input string
	s = make([]string, 0) // Creating an empty stack
	c = 0 // Initializing the counter to zero

	// Iterating through each character in the input string
	for i := 0; i < len(x); i++ {
		s = append(s, string(x[i])) // Pushing the character onto the stack

		// Popping two characters from the stack and checking for a pair
		for len(s) > 1 {
			p := s[len(s)-1] // Popping the top character
			q := s[len(s)-2] // Popping the second top character
			s = s[:len(s)-2] // Removing the top two characters from the stack

			// If the popped characters form a pair, increment the counter and continue
			if (p == "1" && q == "0") || (p == "0" && q == "1") {
				c++
				continue
			}

			// If the characters don't form a pair, push them back onto the stack and break
			s = append(s, q, p)
			break
		}
	}

	// Writing the output to the console
	fmt.Println(c * 2)
}

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSuffix(line, "\n")
}

// 