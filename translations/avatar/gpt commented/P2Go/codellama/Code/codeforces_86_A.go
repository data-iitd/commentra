package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Read the input values for l and r, which define the range
	l, r := [2]int{}, [2]int{}
	fmt.Scan(&l[0], &l[1])
	fmt.Scan(&r[0], &r[1])

	// Initialize the current value to r and a counter for the number of digits
	curr := r[1]
	s := 0

	// Count the number of digits in the current value (r)
	for curr > 0 {
		s++
		curr /= 10
	}

	// Calculate the first power of ten greater than r
	first := 10 ** s

	// Calculate the second value as half of the first power of ten
	second := first / 2

	// Initialize the answer variable to store the maximum product found
	ans := -1

	// Iterate through the possible candidates: l, r, first, and second
	for _, i := range []int{l[1], r[1], first, second} {
		// Check if the candidate is within the range [l, r]
		if i >= l[1] && i <= r[1] {
			curr = i
			rev := ""

			// Create the reverse number by subtracting each digit from 9
			for _, k := range strconv.Itoa(curr) {
				rev += strconv.Itoa(9 - int(k - '0'))
			}

			// Update the answer with the maximum product of the current number and its reverse
			ans = max(ans, strconv.Atoi(rev)*curr)
		}
	}

	// Print the maximum product found
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

