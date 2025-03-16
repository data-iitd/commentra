

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Taking input from the user and processing it to create a list of integers
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &A[i])
	}

	// Modifying the list A to include only elements where the previous element is greater than or equal to the current element
	A = append([]int{A[0]}, A[1:]...)
	for i := 1; i < len(A); i++ {
		for j := i; j > 0 && A[j-1] >= A[j]; j-- {
			A[j], A[j-1] = A[j-1], A[j]
		}
	}

	// Storing the length of the modified list A in N
	N := len(A)

	// Function to cut a list of tuples based on a given index
	cut := func(array [][2]int, index int) [][2]int {
		if index < 1 {
			return [][2]int{}
		}
		if index <= array[0][0] {
			return [][2]int{{index, array[0][1]}}
		}
		for i := len(array) - 1; i > 0; i-- {
			if array[i-1][0] < index {
				return append(array[:i], [][2]int{{index, array[i][1]}}...)
			}
		}
		return array
	}

	// Function to check if a given value of K is possible by modifying the list dp
	isPossible := func(K int) bool {
		dp := [][2]int{{A[0], 0}}
		for i := 1; i < N; i++ {
			if A[i] <= dp[len(dp)-1][0] {
				dp = cut(dp, A[i])
			} else {
				dp = append(dp, [2]int{A[i], 0})
			}
			isAdded := false
			for j := len(dp) - 1; j >= 0; j-- {
				if dp[j][1] < K-1 {
					dp = append(cut(dp, dp[j][0]-1), [2]int{dp[j][0], dp[j][1] + 1})
					if dp[len(dp)-1][0] < A[i] {
						dp = append(dp, [2]int{A[i], 0})
					}
					isAdded = true
					break
				}
			}
			if!isAdded {
				return false
			}
		}
		return true
	}

	// Function to perform a binary search to find the maximum possible value of K
	bis := func(x, y int) int {
		if y == x+1 {
			return y
		}
		if isPossible((x+y)/2) {
			return bis(x, (x+y)/2)
		} else {
			return bis((x+y)/2, y)
		}
	}

	// Printing the result of the binary search
	fmt.Println(bis(0, N))
}

