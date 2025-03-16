
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Initialize a new scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer from standard input
func ri() (n int) {
	sc.Scan() // Scan the next token from input
	for _, v := range sc.Bytes() { // Convert bytes to digits and calculate the number
		n = n*10 + int(v-48)
	}
	return
	// Return the read integer
}

// Function to calculate the average of a slice of float64 numbers
func ave(s []float64) float64 {
	var sum float64 // Initialize a variable to store the sum of numbers in the slice
	for _, v := range s { // Iterate through each number in the slice
		sum += v // Add the current number to the sum
	}
	return float64(sum) / float64(len(s)) // Calculate and return the average
}

// Function to calculate the difference between two float64 numbers
func diff(a, b float64) float64 {
	if a > b { // Check if the first number is greater than the second number
		return a - b // If so, return the difference
	}
	return b - a // If not, return the negative difference
}

// Main function
func main() {
	// Initialize the scanner to read words instead of lines
	sc.Split(bufio.ScanWords)

	// Read the number of elements in the array from standard input
	n := ri()

	// Allocate memory for an array of float64 numbers with the given size
	a := make([]float64, n)

	// Read each element of the array from standard input and store it in the corresponding index
	for i := 0; i < n; i++ {
		a[i] = float64(ri()) // Read an integer from standard input and convert it to a float64 number
	}
	// Print the array for debugging purposes (uncomment this line if needed)
	// fmt.Println(a)

	// Calculate the average of the array elements
	ave := ave(a)

	// Initialize variables to store the minimum difference and the index of the element with the minimum difference
	minDiff := 999999.9
	ansIndex := -1

	// Iterate through each element of the array and find the one with the minimum difference from the average
	for i, v := range a {
		diff := diff(v, ave) // Calculate the difference between the current element and the average
		if diff < minDiff { // Check if the difference is smaller than the current minimum difference
			minDiff = diff // If so, update the minimum difference
			ansIndex = i    // and the index of the answer
		}
	}

	// Print the index of the element with the minimum difference from the average
	fmt.Println(ansIndex)

// End of the code
