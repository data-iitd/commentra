// Importing the fmt module and assigning its stdin input to a variable named 'input'
package main

import (
	"fmt"
	"os"
)

func main() {
	// Assigning the input to two variables 'a' and 'b' after splitting it by a space
	input := os.Stdin.ReadString('\n')
	a, b := input[:len(input)-1], input[len(input)-1:]

	// Finding the maximum length between 'a' and 'b' and padding zeros to the shorter string
	x := max(len(a), len(b))
	a = a + strings.Repeat("0", x-len(a))
	b = strings.Repeat("0", x-len(b)) + b

	// Initializing an empty string 's' and a counter 'c' for carrying
	s := ""
	c := 0

	// Iterating through each index 'i' in the range of the length of the padded strings 'x'
	for i := 0; i < x; i++ {

		// Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
		d := int(b[i]) + int(a[x-i-1]) + c

		// If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
		if d > 9 {
			s += string(d - 10)
			c = 1
		} else {
			// If the sum is less than or equal to 9, add the digit to the result string 's'
			s += string(d)
		}
	}

	// If there is still a carry left, add it to the result string 's'
	if c == 1 {
		s += "1"
	}

	// Printing the final result after removing the leading zeros (if any)
	fmt.Println(s)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 