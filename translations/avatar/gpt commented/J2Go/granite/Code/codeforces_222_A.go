
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements (n) and the threshold (k)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	// Initialize variables to keep track of the last number and the count of consecutive occurrences
	last := 0
	count := 1

	// Loop through each element to count consecutive occurrences
	for scanner.Scan() {
		// Read the next integer from input
		a, _ := strconv.Atoi(scanner.Text())

		// Check if the current number is the same as the last one
		if a == last {
			count += 1 // Increment the count of consecutive occurrences
		} else {
			count = 1 // Reset the count if the number changes
		}

		// Update the last number to the current one
		last = a
	}

	// Check if the count of consecutive numbers plus k exceeds n
	if count+k > n {
		// If true, print the number of elements that are not part of the consecutive sequence
		fmt.Println(n - count)
	} else {
		// Otherwise, print -1 indicating the condition is not met
		fmt.Println(-1)
	}
}

