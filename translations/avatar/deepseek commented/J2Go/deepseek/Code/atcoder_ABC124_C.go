package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the input string
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	// Create two strings to manipulate the string
	a := []rune(input)
	b := []rune(input)
	// Initialize counters for the number of changes needed
	a1 := 0
	a2 := 0

	// First loop to change characters to make the string colorful
	for i := 1; i < len(a); i++ {
		if a[i] == a[i-1] {
			// Change the character to the opposite
			if a[i] == '1' {
				a[i] = '0'
			} else {
				a[i] = '1'
			}
			// Increment the counter
			a1++
		}
	}

	// Second loop to change characters to make the string colorful
	for i := len(b) - 1; i > 0; i-- {
		if b[i] == b[i-1] {
			// Change the character to the opposite
			if b[i-1] == '1' {
				b[i-1] = '0'
			} else {
				b[i-1] = '1'
			}
			// Increment the counter
			a2++
		}
	}

	// Output the minimum number of changes needed
	if a1 < a2 {
		fmt.Println(a1)
	} else {
		fmt.Println(a2)
	}
}
