package main

import (
	"fmt"
)

func main() {
	var k int
	var a [100100]int
	var min, max int

	// Read the number of elements
	fmt.Scan(&k)

	// Read the input values into the array
	for i := 0; i < k; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize max and min values
	max = 3
	min = 2

	// Check if the last element is not equal to 2
	if a[k-1] != 2 {
		fmt.Println(-1)
		return
	}

	// Iterate through the array from the second last element to the first
	for i := k - 2; i >= 0; i-- {
		// If the current element is greater than max, output -1
		if a[i] > max {
			fmt.Println(-1)
			return
		} else {
			// Update max based on the current element
			max = ((max / a[i]) + 1) * a[i] - 1
			// Adjust min to be a multiple of the current element if necessary
			if min%a[i] != 0 {
				min = ((min / a[i]) + 1) * a[i]
			}
		}

		// Check if the updated max is less than or equal to min
		if max <= min {
			fmt.Println(-1)
			return
		}
	}

	// Output the final min and max values
	fmt.Printf("%d %d\n", min, max)
}

