package main

import (
	"fmt"
)

// Function to calculate the number of digits in a given number
func power(a int64) int {
	res := 0
	// Count the number of digits by dividing the number by 10 until it becomes 0
	for a > 0 {
		res++
		a /= 10
	}
	return res
}

// Function to calculate the product of a number and the difference between the largest number with the same number of digits and the number itself
func mult(a int64) int64 {
	pow := power(a) // Get the number of digits in 'a'
	var max int64 = 0
	// Create the largest number with the same number of digits as 'a' (all 9s)
	for j := 0; j < pow; j++ {
		max = max*10 + 9
	}
	// Return the product of 'a' and the difference between the largest number and 'a'
	return a * (max - a)
}

func main() {
	var l, r int64
	// Read the lower and upper bounds of the range
	fmt.Scan(&l, &r)
	res := int64(0) // Variable to store the maximum result
	maxxes := make([]int64, 10) // Array to store maximum products for numbers with different digit lengths
	var temp int64 = 0

	// Precompute maximum products for numbers with up to 10 digits
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9 // Create the largest number with i+1 digits (all 9s)
		maxxes[i] = temp/2 * (temp - temp/2) // Calculate the maximum product for this digit length
	}

	// Calculate the maximum product for the lower bound 'l'
	if mult(l) > res {
		res = mult(l)
	}
	// Calculate the maximum product for the upper bound 'r'
	if mult(r) > res {
		res = mult(r)
	}
	temp = 0

	// Check for numbers formed by all 9s and see if they lie within the range [l, r]
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9 // Create the largest number with i+1 digits (all 9s)
		// If the half of this number is within the range, consider its maximum product
		if l <= temp/2 && temp/2 <= r {
			if maxxes[i] > res {
				res = maxxes[i]
			}
		}
	}

	// Output the maximum product found
	fmt.Println(res)
}
