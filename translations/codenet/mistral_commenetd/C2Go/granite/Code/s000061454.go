

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize variables
	var a, b, n, sum int
	var i, j int

	// Read input values a, b, and n from the user
	reader := bufio.NewReader(os.Stdin)
	for {
		input, err := reader.ReadString('\n')
		if err!= nil {
			break
		}

		// Split the input into individual values
		values := strings.Split(input, " ")
		if len(values)!= 3 {
			continue
		}

		// Convert the input values to integers
		a, _ = strconv.Atoi(values[0])
		b, _ = strconv.Atoi(values[1])
		n, _ = strconv.Atoi(values[2])

		// Calculate a = a - a/b * b
		a -= a / b * b

		// Initialize sum to zero
		sum = 0

		// Perform the main calculation for n times
		for i = 1; i <= n; i++ {
			// Multiply a by 10
			a *= 10

			// Find the largest multiple of b less than or equal to a
			for j = 9; j >= 0; j-- {
				// Check if b*j is less than or equal to a
				if b*j <= a {
					// Subtract the multiple of b from a
					a -= b * j

					// Add the digit j to the sum
					sum += j

					// Break the inner loop since we have found the largest multiple
					break
				}
			}
		}

		// Print the result
		fmt.Println(sum)
	}
}

