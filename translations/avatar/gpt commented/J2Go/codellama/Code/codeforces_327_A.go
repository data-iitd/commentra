package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Check if there is input available
	if scanner.Scan() {
		// Read the size of the array
		n, _ := strconv.Atoi(scanner.Text())
		// Initialize the array to hold n integers
		arr := make([]int, n)

		// Populate the array with user input
		for i := 0; i < n; i++ {
			scanner.Scan()
			arr[i], _ = strconv.Atoi(scanner.Text())
		}

		// Initialize max to the smallest possible integer value
		max := math.MinInt32

		// Iterate through all possible subarrays
		for i := 0; i < n; i++ {
			for j := i; j < n; j++ {
				// Initialize a temporary variable to track the index for brr
				x := 0
				// Create a copy of the original array
				brr := make([]int, n)
				for _, v := range arr {
					brr[x] = v
					x++
				}

				// Flip the values in the subarray from index i to j
				for k := i; k <= j; k++ {
					if brr[k] == 0 {
						brr[k] = 1 // Change 0 to 1
					} else {
						brr[k] = 0 // Change 1 to 0
					}
				}

				// Count the number of 1's in the modified array
				count := checkNo(brr)

				// Update max if the current count is greater
				if count > max {
					max = count
				}
			}
		}

		// Handle the case when there is only one element in the array
		if n == 1 {
			if arr[0] == 1 {
				fmt.Println(0) // Output 0 if the single element is 1
			} else {
				fmt.Println(1) // Output 1 if the single element is 0
			}
		} else {
			// Output the maximum count of 1's found
			fmt.Println(max)
		}
	}
}

// Method to count the number of 1's in the given array
func checkNo(brr []int) int {
	val := 0
	// Count each occurrence of 1 in the array
	for _, v := range brr {
		if v == 1 {
			val++
		}
	}
	return val // Return the total count of 1's
}

