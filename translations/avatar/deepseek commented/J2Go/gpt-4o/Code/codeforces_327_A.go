package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the size of the array
	arr := make([]int, n) // Declaring and initializing the array

	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i]) // Reading the elements of the array
	}

	max := -1 // Initializing max to the minimum possible integer value

	for i := 0; i < n; i++ { // Iterating over all possible starting points of subarrays
		for j := i; j < n; j++ { // Iterating over all possible ending points of subarrays
			brr := make([]int, n) // Declaring and initializing a copy of the array
			copy(brr, arr) // Copying the elements of arr to brr

			for k := i; k <= j; k++ { // Flipping the elements in the current subarray
				if brr[k] == 0 {
					brr[k] = 1
				} else {
					brr[k] = 0
				}
			}

			count := checkNo(brr) // Counting the number of 1s in the modified subarray

			if count > max {
				max = count // Updating max if the current count is greater
			}
		}
	}

	if n == 1 { // Handling the special case of a single element array
		if arr[0] == 1 {
			fmt.Println(0)
		} else {
			fmt.Println(1)
		}
	} else {
		fmt.Println(max) // Printing the maximum count of 1s found
	}
}

func checkNo(brr []int) int { // Helper method to count the number of 1s in an array
	val := 0
	for _, i := range brr {
		if i == 1 {
			val++
		}
	}
	return val
}

// <END-OF-CODE>
