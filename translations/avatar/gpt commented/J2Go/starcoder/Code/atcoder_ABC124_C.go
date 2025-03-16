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
	x := readLine(reader)

	// Create two strings to manipulate the string
	a := x
	b := x

	// Initialize counters for the number of changes made
	a1 := 0
	a2 := 0

	// First pass: modify 'a' from left to right
	for i := 1; i < len(x); i++ {
		// Check if the current character is the same as the previous one
		if a[i] == a[i-1] {
			// Change the character to the opposite value
			if a[i] == '1' {
				a = a[:i] + "0" + a[i+1:]
			} else {
				a = a[:i] + "1" + a[i+1:]
			}

			// Increment the change counter
			a1++
		}
	}

	// Second pass: modify 'b' from right to left
	for i := len(x) - 1; i > 0; i-- {
		// Check if the current character is the same as the previous one
		if b[i] == b[i-1] {
			// Change the previous character to the opposite value
			if b[i-1] == '1' {
				b = b[:i-1] + "0" + b[i:]
			} else {
				b = b[:i-1] + "1" + b[i:]
			}

			// Increment the change counter
			a2++
		}
	}

	// Output the minimum number of changes made in either pass
	fmt.Fprintln(writer, min(a1, a2))

	// Close the output stream
	writer.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return strings.TrimRight(string(str), "\r\n")
}

