
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers from input and assign them to variables a and b
	reader := bufio.NewReader(os.Stdin)
	line, _, _ := reader.ReadLine()
	a, _ := strconv.Atoi(string(line[0:1]))
	b, _ := strconv.Atoi(string(line[2:3]))

	// Initialize a variable c to accumulate the result
	c := 0

	// Loop for 2 iterations
	for i := 0; i < 2; i++ {
		// Add the maximum of a and b to c
		c += max(a, b)

		// Decrease the larger of the two numbers (a or b) by 1
		if a >= b {
			a -= 1 // If a is greater than or equal to b, decrement a
		} else {
			b -= 1 // Otherwise, decrement b
		}
	}

	// Print the final accumulated value of c
	fmt.Println(c)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

