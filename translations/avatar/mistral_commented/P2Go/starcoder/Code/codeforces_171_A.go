
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading input from stdin
	input, _ := os.Stdin.ReadString('\n')

	// Splitting the input by a space
	a, b := strings.Split(input, " ")

	// Finding the maximum length between 'a' and 'b' and padding zeros to the shorter string
	x := max(len(a), len(b))
	a = a.rjust(x, '0')
	b = b.ljust(x, '0')

	// Initializing an empty string's' and a counter 'c' for carrying
	s := ""
	c := 0

	// Iterating through each index 'i' in the range of the length of the padded strings 'x'
	for i := 0; i < x; i++ {

		// Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
		d, _ := strconv.Atoi(b[i : i+1])
		d += int(a[x-i-1]) + c

		// If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
		if d > 9 {
			s += string(d)[1:2]
			c = 1

		// If the sum is less than or equal to 9, add the digit to the result string's'
		} else {
			s += string(d)
			c = 0
		}
	}

	// If there is still a carry left, add it to the result string's'
	if c == 1 {
		s += "1"
	}

	// Printing the final result after removing the leading zeros (if any)
	fmt.Println(s[:len(s)-1])
}

// Finding the maximum length between 'a' and 'b'
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

