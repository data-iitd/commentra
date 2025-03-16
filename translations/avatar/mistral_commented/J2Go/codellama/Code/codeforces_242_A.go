
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read four integers from the console
	var x, y, a, b int
	scanner.Scan()
	x, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	y, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	a, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ = strconv.Atoi(scanner.Text())

	// Initialize a counter variable
	var count int

	// Find the number of pairs (i, j) that satisfy the condition i < j
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			// If i is less than j, continue to the next iteration of the inner loop
			if i <= j {
				continue
			}

			// Increment the counter if the condition is satisfied
			count++
		}
	}

	// Print the result
	fmt.Println(count)

	// Print all pairs (i, j) that satisfy the condition i < j
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			// If i is less than j, print the pair
			if i <= j {
				fmt.Println(i, j)
			}
		}
	}

	// Close the Scanner object to free system resources
	scanner.Close()
}

