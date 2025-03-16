package main

import (
	"fmt"
	"sort"
)

func main() {
	var input string
	fmt.Scanln(&input) // Taking input from the user
	var A []int
	fmt.Scan(&A) // Read integers into slice A

	// Modifying the list A to include only elements where the previous element is greater than or equal to the current element
	A = modifyList(A)

	// Storing the length of the modified list A in N
	N := len(A)

	// Printing the result of the binary search
	fmt.Println(bis(0, N, A))
}

// Function to modify the list A
func modifyList(A []int) []int {
	if len(A) == 0 {
		return A
	}
	result := []int{A[0]}
	for i := 1; i < len(A); i++ {
		if A[i-1] >= A[i] {
			result = append(result, A[i])
		}
	}
	return result
}

// Function to cut a list of tuples based on a given index
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
	return array
}

// Function to check if a given value of K is possible by modifying the list dp
func isPossible(K int, A []int) bool {
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

// Function to perform a binary search to find the maximum possible value of K
func bis(x, y int, A []int) int {
	if y == x+1 {
		return y
	} else if isPossible((x+y)/2, A) {
		return bis(x, (x+y)/2, A)
	} else {
		return bis((x+y)/2, y, A)
	}
}
