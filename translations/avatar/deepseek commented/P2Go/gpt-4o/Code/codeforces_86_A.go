package main

import (
	"fmt"
	"math"
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
	}
	// Determine the number of digits in r and store it in s

	first := int(math.Pow(10, float64(s)))
	second := first / 2
	// Calculate the smallest number with s digits and its half

	ans := -1
	// Initialize ans to -1 to store the maximum product found

	for _, i := range []int{l, r, first, second} {
		if i >= l && i <= r {
			curr := i
			rev := ""
			for _, k := range fmt.Sprint(curr) {
				rev += fmt.Sprint(9 - int(k-'0'))
			}
			if product := int(rev) * curr; product > ans {
				ans = product
			}
		}
	}
	// Iterate over the specified numbers, check if they are within the range,
	// reverse the digits, calculate the product, and update ans if necessary

	fmt.Println(ans)
	// Print the maximum product found
}

// <END-OF-CODE>
