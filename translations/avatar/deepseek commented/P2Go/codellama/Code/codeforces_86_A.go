
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var l, r int
	fmt.Scan(&l, &r)
	// Taking the range as input from the user

	curr := r
	s := 0
	// Initialize curr to r and s to 0

	for curr > 0 {
		s++
		curr /= 10
		// Determine the number of digits in r and store it in s
	}

	first := 10 ** s
	second := first / 2
	// Calculate the smallest number with s digits and its half

	ans := -1
	// Initialize ans to -1 to store the maximum product found

	for i := l; i <= r; i++ {
		if i >= l && i <= r {
			curr = i
			rev := ""
			for _, k := range strconv.Itoa(curr) {
				rev += string(9 - int(k))
			}
			ans = max(ans, strconv.Atoi(rev)*curr)
			// Iterate over the specified numbers, check if they are within the range,
			// reverse the digits, calculate the product, and update ans if necessary
		}
	}

	fmt.Println(ans)
	// Print the maximum product found
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

