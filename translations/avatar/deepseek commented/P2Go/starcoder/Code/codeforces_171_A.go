package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input and split into two strings, a and b
	a, b := readInput()

	// Determine the maximum length of the two strings
	x := max(len(a), len(b))

	// Pad the shorter string with zeros on the left
	a = strings.Repeat("0", x-len(a)) + a

	// Pad the shorter string with zeros on the right
	b = b + strings.Repeat("0", x-len(b))

	// Initialize an empty string to store the result
	s := ""

	// Initialize carry to 0
	c := 0

	// Loop through each digit from right to left
	for i := x - 1; i >= 0; i-- {
		// Add the corresponding digits from a and b along with the carry
		d, _ := strconv.Atoi(string(b[i]))
		d += int(a[i]) + c

		// If the sum is greater than 9, set carry to 1 and append the tens digit
		if d > 9 {
			s += string(d)[1]
			c = 1
		} else {
			// Otherwise, append the sum and set carry to 0
			s += string(d)
			c = 0
	}

	// If there's a carry left after the final addition, append '1'
	if c == 1 {
		s += "1"
	}

	// Reverse the result string and print it as an integer
	fmt.Println(reverse(s))
}

func readInput() (string, string) {
	// Read input from stdin
	input, _ := os.Stdin.ReadString('\n')

	// Split into two strings, a and b
	a, b := strings.Split(input, " ")

	return a, b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func reverse(s string) int {
	// Reverse the string
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}

	// Convert the reversed string to an integer
	i, _ := strconv.Atoi(string(r))

	return i
}

