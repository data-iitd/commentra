package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read a long integer from stdin
	text, _ := reader.ReadString('\n')
	x, _ := strconv.ParseInt(strings.TrimSpace(text), 10, 64)

	// Initialize a list to store the digits after transformation
	list := make([]int, 0)

	// Process each digit of the number until there are no digits left
	for x > 0 {
		// Extract the last digit of the number
		r := x % 10

		// Determine whether to keep the digit or replace it with its complement to 9
		if 9-r < r {
			// If the digit is the last one and its complement is 0, keep the digit
			if x/10 == 0 && 9-r == 0 {
				list = append(list, int(r))
			} else {
				// Otherwise, add the complement to the list
				list = append(list, 9-r)
			}
		} else {
			// If the digit is less than or equal to its complement, keep the digit
			list = append(list, int(r))
		}

		// Remove the last digit from the number
		x = x / 10
	}

	// Initialize variables to construct the new number
	pow := 0
	newNumber := 0

	// Reconstruct the new number from the transformed digits
	for i := 0; i < len(list); i++ {
		newNumber = newNumber + list[i]*int(math.Pow(10, float64(pow)))
		pow++
	}

	// Output the newly constructed number
	fmt.Println(newNumber)
}

