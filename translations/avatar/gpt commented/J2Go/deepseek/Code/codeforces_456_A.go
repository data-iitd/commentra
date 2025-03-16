package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new Scanner for reading input
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of pairs (n)
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	
	// Initialize two arrays to hold the pairs of integers
	a := make([]int, n)
	b := make([]int, n)
	
	// Temporary variables for processing
	var temp int // To track the current maximum value in array a
	var q int    // To track the corresponding value in array b
	var w int    // To track the maximum value in array a
	var e int    // To track the corresponding value in array b
	var f bool   // Flag to determine if the condition for "Happy Alex" is met

	// Loop to read pairs of integers into arrays a and b
	for i := 0; i < n; i++ {
		// Read value for array a
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
		
		// Read value for array b
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &b[i])
		
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
	if f {
		fmt.Println("Happy Alex") // Condition met for "Happy Alex"
	} else {
		fmt.Println("Poor Alex")   // Condition not met, output "Poor Alex"
	}
}
