

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize variables
	N, D, X := readInt() // Number of days, maximum days, and extra chocolate
	A := make([]int, N) // Array to store the number of chocolate pieces for each day
	num_of_chocolate := 0 // Total number of chocolate pieces
	counter := 0 // Number of chocolate pieces eaten in one day
	days := 0 // Number of days eaten from one chocolate piece

	// Read input
	for i := 0; i < N; i++ {
		A[i] = readInt() // Read the number of chocolate pieces for the i-th day
	}

	// Calculate the total number of chocolate pieces
	for i := 0; i < N; i++ {
		// Initialize variables for inner loop
		days = 0
		counter = 0

		// Calculate the number of days this chocolate piece lasts
		for j := 0;; j++ {
			days = j * A[i] + 1 // Calculate the number of days
			if days <= D { // Check if the number of days is less than or equal to the maximum number of days
				counter++ // Increment the counter
			} else { // If the number of days is greater than the maximum number of days, break the loop
				break
			}
		}

		// Add the number of chocolate pieces eaten in this day to the total number of chocolate pieces
		num_of_chocolate = num_of_chocolate + counter
	}

	// Add the extra chocolate
	num_of_chocolate = num_of_chocolate + X

	// Output the result
	fmt.Println(num_of_chocolate)
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

