package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare a string variable to hold the input
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	
	// Initialize variables to track the maximum length of valid characters and the current count
	max, cnt := 0, 0
	
	// Iterate through each character in the input string
	for _, sc := range input {
		// Check if the character is one of the valid DNA bases
		if sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T' {
			// Increment the count for consecutive valid characters
			cnt++
		} else {
			// Reset the count if an invalid character is encountered
			cnt = 0
		}
		// Update the maximum length if the current count exceeds the previous maximum
		if max < cnt {
			max = cnt
		}
	}
	
	// Output the maximum length of consecutive valid characters found
	fmt.Println(max)
}
