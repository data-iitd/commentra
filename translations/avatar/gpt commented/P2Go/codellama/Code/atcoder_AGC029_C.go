
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Read input from the user
	fmt.Scanln()

	// Parse the input into a list of integers
	A := make([]int, 0)
	for _, s := range strings.Split(fmt.Scanln(), " ") {
		i, _ := strconv.Atoi(s)
		A = append(A, i)
	}

	// Filter the list to keep only non-increasing elements
	A = append(A[:1], A[1:]...)
	for i := 1; i < len(A); i++ {
		if A[i] <= A[i-1] {
			A = append(A[:i], A[i:]...)
			i--
		}
	}

	// Get the length of the filtered list
	N := len(A)

	// Function to cut the array based on a given index
	cut := func(array []int, index int) []int {
		// If the index is less than 1, return an empty list
		if index < 1 {
			return []int{}
		}

		// If the index is less than or equal to the first element, return it with the first element's second value
		if index <= array[0] {
			return []int{index, array[0]}
		}

		// Iterate backwards through the array to find the appropriate cut point
		for i := len(array) - 1; i > 0; i-- {
			if array[i-1] < index {
				return array[:i]
			}
		}

		return []int{}
	}

	// Function to check if a certain condition is possible with K
	isPossible := func(K int) bool {
		// Initialize the dynamic programming array with the first element
		dp := []int{A[0], 0}

		// Iterate through the remaining elements in A
		for _, a := range A[1:] {
			// If the current element is less than or equal to the last element in dp, cut dp
			if a <= dp[0] {
				dp = cut(dp, a)
			} else {
				// Otherwise, append the current element to dp
				dp = append(dp, a)
			}

			isAdded := false

			// Iterate backwards through dp to check conditions
			for j := len(dp) - 1; j > 0; j-- {
				// If the second value of the current tuple is less than K-1
				if dp[j][1] < K-1 {
					// Cut dp and increment the second value of the current tuple
					dp = cut(dp, dp[j][0]-1)
					dp = append(dp, []int{dp[j][0], dp[j][1] + 1}...)

					// If the last element in dp is less than a, append a to dp
					if dp[len(dp)-1][0] < a {
						dp = append(dp, a)
					}

					isAdded = true
					break
				}
			}

			// If no element was added, return False
			if !isAdded {
				return false
			}
		}

		// If all conditions are satisfied, return True
		return true
	}

	// Function to perform binary search to find the maximum K
	bis := func(x, y int) int {
		// If the range is narrowed down to one element, return y
		if y == x+1 {
			return y
		}

		// If is_possible is true for the midpoint, search in the left half
		if isPossible((x + y) / 2) {
			return bis(x, (x + y) / 2)
		}

		// Otherwise, search in the right half
		return bis((x + y) / 2, y)
	}

	// Print the result of the binary search
	fmt.Println(bis(0, N))
}

