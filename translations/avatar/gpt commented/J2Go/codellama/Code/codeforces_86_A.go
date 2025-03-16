
package main

import (
	"fmt"
	"math"
)

// Function to calculate the number of digits in a given number
func power(a int64) int {
	res := 0
	// Count the number of digits by dividing the number by 10 until it becomes 0
	for a > 0 {
		res++
		a = a / 10
	}
	return res
}

// Function to calculate the product of a number and the difference between the largest number with the same number of digits and the number itself
func mult(a int64) int64 {
	pow := power(a) // Get the number of digits in 'a'
	max := int64(0)
	// Create the largest number with the same number of digits as 'a' (all 9s)
	for j := 0; j < pow; j++ {
		max = max*10 + 9
	}
	// Return the product of 'a' and the difference between the largest number and 'a'
	return a * (max - a)
}

func main() {
	var l, r int64
	fmt.Scan(&l, &r) // Read the lower bound of the range
	res := int64(0)  // Variable to store the maximum result
	maxxes := make([]int64, 10)
	temp := int64(0)

	// Precompute maximum products for numbers with up to 10 digits
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9 // Create the largest number with i+1 digits (all 9s)
		maxxes[i] = temp/2 * (temp - temp/2) // Calculate the maximum product for this digit length
	}

	// Calculate the maximum product for the lower bound 'l'
	res = int64(math.Max(float64(mult(l)), float64(res)))
	// Calculate the maximum product for the upper bound 'r'
	res = int64(math.Max(float64(mult(r)), float64(res)))
	temp = int64(0)

	// Check for numbers formed by all 9s and see if they lie within the range [l, r]
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9 // Create the largest number with i+1 digits (all 9s)
		// If the half of this number is within the range, consider its maximum product
		if l <= temp/2 && temp/2 <= r {
			res = int64(math.Max(float64(maxxes[i]), float64(res)))
		}
	}

	// Output the maximum product found
	fmt.Println(res)
}

