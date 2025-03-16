package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Use bufio for faster input
	reader := bufio.NewReader(os.Stdin)

	// Read input and split into two strings a and b, removing the trailing newline
	a, b := strings.Split(strings.TrimSpace(reader.ReadString()), " ")[0], strings.Split(strings.TrimSpace(reader.ReadString()), " ")[0]

	// Determine the maximum length of the two strings
	x := max(len(a), len(b))

	// Right-justify 'a' and left-justify 'b' to ensure both have the same length, padding with '0'
	a = strings.Repeat("0", x-len(a)) + a
	b = b + strings.Repeat("0", x-len(b))

	// Initialize an empty string to store the result and a carry variable
	s := ""
	c := 0

	// Iterate over each digit from the least significant to the most significant
	for i := 0; i < x; i++ {
		// Calculate the sum of the corresponding digits and the carry
		d, _ := strconv.Atoi(string(b[i]))+strconv.Atoi(string(a[x-i-1]))+c

		// Check if the sum exceeds 9, which requires a carry
		if d > 9 {
			s += string(d)[1]  // Append the last digit of the sum to the result
			c = 1  // Set carry to 1 for the next iteration
		} else {
			s += string(d)  // Append the sum to the result
			c = 0  // Reset carry to 0
	}

	// If there's a carry left after the last addition, append '1' to the result
	if c == 1 {
		s += "1"
	}

	// Print the final result, reversing the string to get the correct order and converting to int to remove leading zeros
	fmt.Println(strconv.Atoi(s[::-1]))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

