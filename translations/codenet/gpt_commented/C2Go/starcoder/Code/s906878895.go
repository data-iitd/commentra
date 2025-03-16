package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables to hold two integers and intermediate results
	var a, b, x, w int

	// Continuously read pairs of integers until EOF (End of File) is reached
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Split the input string into two space-separated integers
		input := strings.Split(scanner.Text(), " ")
		a, _ = strconv.Atoi(input[0])
		b, _ = strconv.Atoi(input[1])

		// Calculate the sum of the two integers
		x = a + b

		// Initialize a counter for the number of digits in the sum
		w = 0

		// Count the number of digits in the sum (x)
		for x > 0 {
			// Increment the digit counter
			w++
			// Remove the last digit from x by dividing by 10
			x /= 10
		}

		// Print the number of digits in the sum
		fmt.Println(w)
	}
}

