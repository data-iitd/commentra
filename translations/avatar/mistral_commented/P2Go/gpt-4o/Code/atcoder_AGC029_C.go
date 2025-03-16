package main

import (
	"fmt"
	"strconv"
	"strings"
)

// Function to cut the array based on the index
func cut(array [][2]int, index int) [][2]int {
	if index < 1 {
		return nil
	}
	if index <= array[0][0] {
		return [][2]int{{index, array[0][1]}}
	}
	for i := len(array) - 1; i > 0; i-- {
		if array[i-1][0] < index {
			return append(array[:i], [2]int{index, array[i][1]})
		}
	}
	return nil
}

// Function to check if it's possible to add K elements
func isPossible(A []int, K int) bool {
	dp := [][2]int{{A[0], 0}}

	for _, a := range A[1:] {
		if a <= dp[len(dp)-1][0] {
			dp = cut(dp, a)
		}
		dp = append(dp, [2]int{a, 0})

		isAdded := false
		for j := len(dp) - 1; j >= 0; j-- {
			if dp[j][1] < K-1 {
				dp = append(cut(dp, dp[j][0]-1), [2]int{dp[j][0], dp[j][1] + 1})
				if dp[len(dp)-1][0] < a {
					dp = append(dp, [2]int{a, 0})
					isAdded = true
					break
				}
			}
		}
		if !isAdded {
			return false
		}
	}
	return true
}

// Function to find the binary index
func bis(x, y int, A []int) int {
	if y == x+1 {
		return y
	}
	mid := (x + y) / 2
	if isPossible(A, mid) {
		return bis(x, mid, A)
	}
	return bis(mid, y, A)
}

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Fields(input)
	A := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		A[i] = num
	}

	// Adding the first element to the beginning of the list
	A = append([]int{A[0]}, A[1:]...)
	N := len(A)

	// Printing the result of the binary index function
	fmt.Println(bis(0, N, A))
}

// <END-OF-CODE>
