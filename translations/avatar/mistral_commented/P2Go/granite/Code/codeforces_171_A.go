
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Assigning the input to two variables 'a' and 'b' after splitting it by a space
	input := bufio.NewReader(os.Stdin)
	a, b := strings.Split(inputReadLine(input), " ")

	// Finding the maximum length between 'a' and 'b' and padding zeros to the shorter string
	x := max(len(a), len(b))
	a = strings.Repeat("0", x-len(a)) + a
	b = strings.Repeat("0", x-len(b)) + b

	// Initializing an empty string's' and a counter 'c' for carrying
	s := ""
	c := 0

	// Iterating through each index 'i' in the range of the length of the padded strings 'x'
	for i := 0; i < x; i++ {

		// Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
		d := int(b[i]) + int(a[x-i-1]) + c

		// If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
		if d > 9 {
			s += string(d/10 + '0')
			c = 1
		} else {
			s += string(d + '0')
		}
	}

	// If there is still a carry left, add it to the result string's'
	if c == 1 {
		s += "1"
	}

	// Printing the final result after removing the leading zeros (if any)
	fmt.Println(strings.TrimLeft(s, "0"))
}

func inputReadLine(input *bufio.Reader) string {
	line, _, err := input.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	// Assigning the input to two variables 'a' and 'b' after splitting it by a space
	input := bufio.NewReader(os.Stdin)
	a, b := strings.Split(inputReadLine(input), " ")

	// Finding the maximum length between 'a' and 'b' and padding zeros to the shorter string
	x := max(len(a), len(b))
	a = strings.Repeat("0", x-len(a)) + a
	b = strings.Repeat("0", x-len(b)) + b

	// Initializing an empty string's' and a counter 'c' for carrying
	s := ""
	c := 0

	// Iterating through each index 'i' in the range of the length of the padded strings 'x'
	for i := 0; i < x; i++ {

		// Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
		d := int(b[i]) + int(a[x-i-1]) + c

		// If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
		if d > 9 {
			s += string(d/10 + '0')
			c = 1
		} else {
			s += string(d + '0')
		}
	}

	// If there is still a carry left, add it to the result string's'
	if c == 1 {
		s += "1"
	}

	// Printing the final result after removing the leading zeros (if any)
	fmt.Println(strings.TrimLeft(s, "0"))
}

func inputReadLine(input *bufio.Reader) string {
	line, _, err := input.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

