package main

import (
	"fmt"
	"math"
)

func main() {
	// Taking the number of elements N and the number of queries K as input
	var N, K int
	fmt.Scan(&N, &K)

	// Creating slices to store positive numbers and negative numbers
	lst := make([]int, N)
	lst_p := []int{}
	lst_m := []int{}

	// Taking the list of numbers as input
	for i := 0; i < N; i++ {
		fmt.Scan(&lst[i])
	}

	// Iterating through the list to find positive and negative numbers
	for i := 0; i < N; i++ {
		if lst[i] == 0 {
			K--
		} else if lst[i] > 0 {
			lst_p = append(lst_p, lst[i])
		} else if lst[i] < 0 {
			lst_m = append(lst_m, lst[i])
		}
	}

	// Initializing variables p and m to 0 and setting the initial values of x and y
	p, m := 0, 0
	lastx := len(lst_p)
	lasty := len(lst_m)

	// Function to check the minimum number of moves required
	check := func(k int) int {
		// Initializing the answer as a large number
		ans := math.MaxInt64

		// Iterating through all possible combinations of taking elements from positive and negative lists
		for j := 0; j <= k; j++ {
			if j > lastx || k-j > lasty {
				continue
			}

			// If j is 0, then p is initialized to 0
			if j == 0 {
				p = 0
			} else {
				p = lst_p[j-1]
			}

			// If k - j is 0, then m is initialized to 0
			if k-j == 0 {
				m = 0
			} else {
				m = lst_m[lasty-(k-j)]
			}

			// Updating the answer with the minimum of the current answer
			ans = min(ans, 2*p+abs(m), p+2*abs(m))
		}

		// Returning the answer
		return ans
	}

	// Printing the minimum number of moves required
	fmt.Println(check(K))
}

// Helper function to find the minimum of three integers
func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
		return c
	}
	if b < c {
		return b
	}
	return c
}

// Helper function to return the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// <END-OF-CODE>
