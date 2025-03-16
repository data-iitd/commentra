package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the entire line of input
	scanner.Scan()
	s := scanner.Text()

	// Check if all characters in the string are the same
	if len(strings.Unique(s)) == 1 {
		fmt.Println(0) // If true, print 0 and exit
		return
	}

	// Count the occurrences of each character in the string
	a := make(map[rune]int)
	for _, char := range s {
		a[char]++
	}

	// Calculate the answer as twice the minimum frequency of any character
	minFreq := int(^uint(0) >> 1) // Initialize to maximum possible integer value
	for _, freq := range a {
		if freq < minFreq {
			minFreq = freq
		}
	}
	ans := minFreq * 2

	// Print the final answer
	fmt.Println(ans)
}
