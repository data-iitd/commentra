
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

// Main function
func main() {
	// Read input
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of days: ")
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Print("Enter the maximum number of days: ")
	input, _ = reader.ReadString('\n')
	D, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Print("Enter the extra chocolate: ")
	input, _ = reader.ReadString('\n')
	X, _ := strconv.Atoi(strings.TrimSpace(input))

	// Initialize array A to store the number of chocolate pieces for each day
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Print("Enter the number of chocolate pieces for the ", i+1, "-th day: ")
		input, _ = reader.ReadString('\n')
		A[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}

	// Calculate the total number of chocolate pieces
	num_of_chocolate := 0
	for i := 0; i < N; i++ {
		// Initialize variables for inner loop
		days := 0
		counter := 0

		// Calculate the number of days this chocolate piece lasts
		for j := 0; ; j++ {
			days = j*A[i] + 1
			if days <= D {
				counter++
			} else {
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

