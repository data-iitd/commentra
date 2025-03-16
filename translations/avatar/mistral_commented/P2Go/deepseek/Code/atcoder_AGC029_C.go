package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Helper function to find the index of the last occurrence of an element
// in a list, and the index and value of the previous occurrence
func cut(array [][]int, index int) [][]int {
	// Base case: if index is less than 1, return an empty list
	if index < 1 {
		return [][]int{}
	}

	// Base case: if index is less than or equal to the first element in the array
	if index <= array[0][0] {
		return [][]int{{index, array[0][1]}}
	}

	// Iterating through the array from the end to the beginning
	for i := len(array) - 1; i > 0; i-- {
		// If the previous element is smaller than the index, return the sublist up to that index
		if array[i-1][0] < index {
			return append(array[:i], []int{index, array[i][1]})
		}
	}
	return array
}

// Helper function to check if it's possible to add a certain number of elements
// to the list while maintaining the condition that the previous element is smaller than the current one
func isPossible(K int, A []int) bool {
	// Initializing an empty list to store the indices and values of the elements in the list
	dp := [][]int{{A[0], 0}}

	// Iterating through the list starting from the second element
	for _, a := range A[1:] {
		// If the current element is smaller than the last element in the dp list,
		// we need to cut the list at the previous index and add the current element
		if a <= dp[len(dp)-1][0] {
			dp = cut(dp, a)
		}

		// Adding the current element to the dp list
		dp = append(dp, []int{a, 0})

		// Initializing a flag to check if we need to add an element to the dp list
		isAdded := false

		// Iterating through the dp list from the end to the beginning
		for j := len(dp) - 1; j >= 0; j-- {
			// If the previous element has a smaller value and enough space to add the current element,
			// we need to cut the list at the previous index and add the current element
			if dp[j][1] < K-1 {
				dp = cut(dp, dp[j][0]-1)
				dp = append(dp, []int{dp[j][0], dp[j][1] + 1})

				// Checking if the last element in the dp list is smaller than the current element
				if dp[len(dp)-1][0] < a {
					dp = append(dp, []int{a, 0})
					isAdded = true
					break
				}
			}
		}

		// If we didn't add an element to the dp list, the current number can't be added
		if !isAdded {
			return false
		}
	}
	return true
}

// Helper function to find the binary index of a number in the list
func bis(x, y int, A []int) int {
	// Base case: if y is one more than x, return y
	if y == x+1 {
		return y
	}

	// Recursively finding the binary index of x and y using the isPossible function
	if isPossible((x+y)/2, A) {
		return bis(x, (x+y)/2, A)
	} else {
		return bis((x+y)/2, y, A)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	parts := strings.Split(input, " ")
	A := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		A = append(A, num)
	}

	// Adding the first element of the list to the beginning of the list
	// to make the first index 0 based instead of 1 based
	A = append([]int{A[0]}, A[1:]...)

	// Assigning the length of the list to a variable for easier reference
	N := len(A)

	// Printing the result of the binary index function
	fmt.Println(bis(0, N, A))
}
