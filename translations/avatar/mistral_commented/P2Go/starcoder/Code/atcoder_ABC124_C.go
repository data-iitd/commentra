package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	// Convert the string to a slice of runes
	s := []rune(strings.TrimSpace(line))
	// Initialize two variables 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the list's' respectively
	even, odd := 0, 0
	// Iterate over the slice's'
	for _, v := range s {
		// Convert the rune to an integer
		i, _ := strconv.Atoi(string(v))
		// Increment the count of '0' if the integer is 0
		if i == 0 {
			even++
		} else {
			odd++
		}
	}
	// Print the minimum difference between the length of the list's' and the sum of the frequencies of '0' and '1' in either half of the list
	fmt.Println(min(len(s)-even, len(s)-odd))
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

