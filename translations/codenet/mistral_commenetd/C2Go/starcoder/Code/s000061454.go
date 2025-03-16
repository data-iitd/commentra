
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
<<<<<<< HEAD
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Loop until EOF
	for {
		// Read a line of input
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}

		// Split the line into individual words
		words := strings.Split(line, " ")

		// Convert the words into integers
		a, _ := strconv.Atoi(words[0])
		b, _ := strconv.Atoi(words[1])
		n, _ := strconv.Atoi(words[2])

		// Calculate a = a - a/b * b
		a -= a / b * b

		// Initialize sum to zero
		sum := 0

		// Perform the main calculation for n times
		for i := 1; i <= n; i++ {
			// Multiply a by 10
			a *= 10

			// Find the largest multiple of b less than or equal to a
			for j := 9; j >= 0; j-- {
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

=======
	var a, b, n, sum int
	var i, j int
	var input string

	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	for {
		// Read input values a, b, and n from the user
		input, _ = reader.ReadString('\n')
		input = strings.TrimSuffix(input, "\n")
		input = strings.TrimSuffix(input, "\r")
		input = strings.TrimSuffix(input, "\r\n")
		input = strings.TrimSuffix(input, "\n\r")
		input = strings.TrimSuffix(input, "\r\r")
		input = strings.TrimSuffix(input, "\n\n")
		input = strings.TrimSuffix(input, "\r\r\n")
		input = strings.TrimSuffix(input, "\n\n\r")
		input = strings.TrimSuffix(input, "\r\n\r")
		input = strings.TrimSuffix(input, "\n\r\n")
		input = strings.TrimSuffix(input, "\r\n\n")
		input = strings.TrimSuffix(input, "\n\r\r")
		input = strings.TrimSuffix(input, "\r\n\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\n\n")
		input = strings.TrimSuffix(input, "\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\n")
		input = strings.TrimSuffix(input, "\r\n\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r
>>>>>>> 98c87cb78a (data updated)
