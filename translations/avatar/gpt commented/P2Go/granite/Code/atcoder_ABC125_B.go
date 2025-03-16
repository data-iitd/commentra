
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Read the values into a slice and convert them to integers
	V := make([]int, N)
	for i := 0; i < N; i++ {
		V[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	}

	// Read the costs into a slice and convert them to integers
	C := make([]int, N)
	for i := 0; i < N; i++ {
		C[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	}

	// Initialize a slice to store the profit differences, starting with 0
	profit_differences := []int{0}

	// Initialize a variable to hold the total profit
	ans := 0

	// Initialize variables to hold current value and cost
	X := 0
	Y := 0

	// Iterate through each item
	for i := 0; i < N; i++ {
		// Check if the value is greater than the cost
		if V[i]-C[i] > 0 {
			// Assign the current value and cost to X and Y
			X = V[i]
			Y = C[i]
			// Calculate the profit and append it to the profit differences slice
			profit_differences = append(profit_differences, X-Y)
		}
	}

	// Calculate and print the total profit by summing the profit differences
	fmt.Println(sum(profit_differences))
}

func sum(s []int) int {
	sum := 0
	for _, v := range s {
		sum += v
	}
	return sum
}

