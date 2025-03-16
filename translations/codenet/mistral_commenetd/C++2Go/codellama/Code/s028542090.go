
package main

import (
	"fmt"
)

func main() {
	var k int // Variable to store the number of input numbers
	var a [100100]int // An array of size 100100 to store input numbers
	var min, max int // Variables to store the minimum and maximum values respectively

	fmt.Scan(&k) // Read the number of input numbers from the standard input

	for i := 0; i < k; i++ { // Iterate through each input number and read it into the array
		fmt.Scan(&a[i])
	}

	// Check if the last number in the array is 2
	if a[k - 1] != 2 {
		fmt.Println(-1) // If not, print -1 and exit the program
		return
	}

	// Initialize minimum and maximum values
	max = 3
	min = 2

	// Iterate through the array from the second last number to the first number
	for i := k - 2; i >= 0; i-- {
		// If the current number is greater than the maximum value, print -1 and exit the program
		if a[i] > max {
			fmt.Println(-1)
			return
		} else {
			// Update the maximum value based on the current number
			max = ((max / a[i]) + 1) * a[i] - 1

			// If the current number does not divide the minimum value evenly, update the minimum value
			if min % a[i] != 0 {
				min = ((min / a[i]) + 1) * a[i]
			}
		}

		// Check if the minimum value is less than or equal to the maximum value
		if max <= min {
			fmt.Println(-1) // If so, print -1 and exit the program
			return
		}
	}

	// Print the minimum and maximum values
	fmt.Println(min, max)
}

