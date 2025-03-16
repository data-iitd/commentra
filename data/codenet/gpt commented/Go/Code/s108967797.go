package main

import (
	"bufio"
	"fmt"
	"os"
)

// Initialize a new scanner to read from standard input
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer from input
func ri() (n int) {
	sc.Scan() // Read the next line of input
	for _, v := range sc.Bytes() { // Iterate over each byte in the input
		n = n*10 + int(v-48) // Convert byte to integer and accumulate
	}
	return // Return the accumulated integer
}

// Function to calculate the average of a slice of float64 numbers
func ave(s []float64) float64 {
	var sum float64
	for _, v := range s { // Iterate over each value in the slice
		sum += v // Accumulate the sum of the values
	}
	return float64(sum) / float64(len(s)) // Return the average
}

// Function to calculate the absolute difference between two float64 numbers
func diff(a, b float64) float64 {
	if a > b {
		return a - b // Return the difference if a is greater than b
	}
	return b - a // Return the difference if b is greater than or equal to a
}

func main() {
	sc.Split(bufio.ScanWords) // Set the scanner to split input by words
	n := ri() // Read the number of elements
	a := make([]float64, n) // Create a slice to hold the float64 numbers
	for i := 0; i < n; i++ {
		a[i] = float64(ri()) // Read each integer and convert it to float64
	}
	// fmt.Println(a) // Uncomment to print the array of float64 numbers

	// Calculate the average of the numbers
	ave := ave(a)

	// Initialize variables to track the minimum difference and the corresponding index
	minDiff := 999999.9
	ansIndex := -1
	for i, v := range a { // Iterate over the slice to find the closest value to the average
		diff := diff(v, ave) // Calculate the difference between the current value and the average
		if diff < minDiff { // Check if the current difference is less than the minimum difference found so far
			minDiff = diff // Update the minimum difference
			ansIndex = i // Update the index of the closest value
		}
	}
	// Print the index of the value closest to the average
	fmt.Println(ansIndex)
}
