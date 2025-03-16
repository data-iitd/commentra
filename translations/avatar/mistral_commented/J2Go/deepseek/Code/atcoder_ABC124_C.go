package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read from standard input
	reader := bufio.NewReader(os.Stdin)
	// Write to standard output
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the input string
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	// Initialize counters for number of consecutive '1's in string 'a' and 'b'
	a1 := 0
	a2 := 0

	// Create a new string 'a' with the same string as 'input'
	a := []rune(input)
	// Create a new string 'b' with the same string as 'input'
	b := []rune(input)

	// Loop through each character in string 'a' starting from index 1
	for i := 1; i < len(a); i++ {
		if a[i] == a[i-1] {
			if a[i] == '1' {
				a[i] = '0'
			} else {
				a[i] = '1'
			}
			a1++
		}
	}

	// Loop through each character in string 'b' starting from the last character
	for i := len(b) - 1; i > 0; i-- {
		if b[i] == b[i-1] {
			if b[i-1] == '1' {
				b[i-1] = '0'
			} else {
				b[i-1] = '1'
			}
			a2++
		}
	}

	// Print the minimum number of consecutive '1's in strings 'a' and 'b'
	fmt.Println(min(a1, a2))
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

