
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare a string variable to hold the input
	var str string
	// Read input string from the user
	reader := bufio.NewReader(os.Stdin)
	str, _ = reader.ReadString('\n')
	str = strings.TrimSpace(str)

	// Initialize variables to track the maximum length of valid characters and the current count
	max := 0
	cnt := 0

	// Iterate through each character in the input string
	for _, sc := range str {
		// Check if the character is one of the valid DNA bases
		if sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T' {
			// Increment the count for consecutive valid characters
			cnt++
		} else {
			// Reset the count if an invalid character is encountered
			cnt = 0
		}
		// Update the maximum length if the current count exceeds the previous maximum
		if cnt > max {
			max = cnt
		}
	}

	// Output the maximum length of consecutive valid characters found
	fmt.Println(max)
}
