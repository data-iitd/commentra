
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input from the command line
	a, b := os.Args[1], os.Args[2]

	// Determine the maximum length of the two strings
	x := len(a)
	if len(b) > x {
		x = len(b)
	}

	// Pad the shorter string with zeros on the left
	a = strings.Repeat("0", x-len(a)) + a

	// Pad the shorter string with zeros on the right
	b = strings.Repeat("0", x-len(b)) + b

	// Initialize an empty string to store the result
	s := ""

	// Initialize carry to 0
	c := 0

	// Loop through each digit from right to left
	for i := 0; i < x; i++ {
		// Add the corresponding digits from a and b along with the carry
		d := int(b[i]) + int(a[x-i-1]) + c

		// If the sum is greater than 9, set carry to 1 and append the tens digit
		if d > 9 {
			s = string(d%10) + s
			c = 1
		} else {
			// Otherwise, append the sum and set carry to 0
			s = string(d) + s
			c = 0
		}
	}

	// If there's a carry left after the final addition, append '1'
	if c == 1 {
		s = "1" + s
	}

	// Convert the result string to an integer and print it
	result, _ := strconv.Atoi(s)
	fmt.Println(result)
}
