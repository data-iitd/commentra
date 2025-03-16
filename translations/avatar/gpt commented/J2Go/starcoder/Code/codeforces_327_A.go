package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewScanner(os.Stdin)

	// Read and save an integer, n, from stdin
	reader.Scan()
	n, _ := strconv.Atoi(reader.Text())

	// Initialize an array of size n
	arr := make([]int, n)

	// Read n integers and store them in the array
	for i := 0; i < n; i++ {
		reader.Scan()
		arr[i], _ = strconv.Atoi(reader.Text())
	}

	// Initialize max to the smallest possible integer value
	max := int(^uint(0) >> 1)

	// Iterate through all possible subarrays
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			// Initialize a temporary variable to track the index for brr
			x := 0
			// Create a copy of the original array
			brr := make([]int, n)
			for k := range arr {
				brr[x] = arr[k]
				x++
			}

			// Flip the values in the subarray from index i to j
			for k := i; k <= j; k++ {
				if brr[k] == 0 {
					brr[k] = 1
				} else {
					brr[k] = 0
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

// Method to count the number of 1's in the given array
func checkNo(brr []int) int {
	val := 0
	// Count each occurrence of 1 in the array
	for i := range brr {
		if brr[i] == 1 {
			val++
		}
	}
	return val // Return the total count of 1's
}

