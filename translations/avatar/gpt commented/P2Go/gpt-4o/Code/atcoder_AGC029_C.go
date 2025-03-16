package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

// Function to cut the array based on a given index
func cut(array [][2]int, index int) [][2]int {
	if index < 1 {
		return nil
	}
	if index <= array[0][0] {
		return [][2]int{{index, array[0][1]}}
	}
	for i := len(array) - 1; i > 0; i-- {
		if array[i-1][0] < index {
			return append(array[:i], [2]int{index, array[i][1]} )
		}
	}
	return nil
}

// Function to check if a certain condition is possible with K
func isPossible(A []int, K int) bool {
	dp := [][2]int{{A[0], 0}}

	for _, a := range A[1:] {
		if a <= dp[len(dp)-1][0] {
			dp = cut(dp, a)
		} else {
			dp = append(dp, [2]int{a, 0})
		}

		isAdded := false

		for j := len(dp) - 1; j >= 0; j-- {
			if dp[j][1] < K-1 {
				dp = cut(dp, dp[j][0]-1)
				dp = append(dp, [2]int{dp[j][0], dp[j][1] + 1})

				if dp[len(dp)-1][0] < a {
					dp = append(dp, [2]int{a, 0})
				}

				isAdded = true
				break
			}
		}

		if !isAdded {
			return false
		}
	}

	return true
}

// Function to perform binary search to find the maximum K
func bis(A []int, x, y int) int {
	if y == x+1 {
		return y
	}
	mid := (x + y) / 2
	if isPossible(A, mid) {
		return bis(A, x, mid)
	}
	return bis(A, mid, y)
}

func main() {
	var input string
	fmt.Scanln(&input) // Read input from the user

	// Parse the input into a list of integers
	input = strings.TrimSpace(input)
	A := make([]int, 0)
	for _, s := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(s)
		A = append(A, num)
	}

	// Filter the list to keep only non-increasing elements
	filteredA := []int{A[0]}
	for i := 1; i < len(A); i++ {
		if A[i-1] >= A[i] {
			filteredA = append(filteredA, A[i])
		}
	}

	// Get the length of the filtered list
	N := len(filteredA)

	// Print the result of the binary search
	fmt.Println(bis(filteredA, 0, N))
}

// <END-OF-CODE>
