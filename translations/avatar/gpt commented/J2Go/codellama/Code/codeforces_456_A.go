package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object for input
	in := make([]int, 0)
	for _, v := range os.Args[1:] {
		i, _ := strconv.Atoi(v)
		in = append(in, i)
	}

	// Read the number of pairs (n)
	n := in[0]

	// Initialize two arrays to hold the pairs of integers
	a := make([]int, n)
	b := make([]int, n)

	// Temporary variables for processing
	temp := 0 // To track the current maximum value in array a
	q := 0    // To track the corresponding value in array b
	w := 0    // To track the maximum value in array a
	e := 0    // To track the corresponding value in array b
	f := false // Flag to determine if the condition for "Happy Alex" is met

	// Loop to read pairs of integers into arrays a and b
	for i := 0; i < n; i++ {
		a[i] = in[i+1] // Read value for array a
		b[i] = in[i+n+1] // Read value for array b

		// Check if the current value in a is greater than the previous maximum
		if temp < a[i] {
			// If the current b value is less than the previous b value, set flag to true
			if q > b[i] {
				f = true
			}
			// Update q and temp with current values
			q = b[i]
			temp = a[i]
		}
		// Check if the current value in a is less than the previous maximum
		if temp > a[i] {
			// If the current b value is greater than the previous b value, set flag to true
			if q < b[i] {
				f = true
			}
			// Update q and temp with current values
			q = b[i]
			temp = a[i]
		}
		// Update the maximum value in a and check conditions for b
		if a[i] > w {
			w = a[i] // Update maximum value in a
			// If the current b value is less than the previous maximum b, set flag to true
			if b[i] < e {
				f = true
			}
			e = b[i] // Update corresponding value in b
		}
		// Check if the current value in a is less than the maximum value
		if a[i] < w {
			// If the current b value is greater than the previous maximum b, set flag to true
			if b[i] > e {
				f = true
			}
		}
	}

	// Output the result based on the flag value
	if f == true {
		fmt.Println("Happy Alex") // Condition met for "Happy Alex"
	} else {
		fmt.Println("Poor Alex") // Condition not met, output "Poor Alex"
	}
}

