package main

import (
	"fmt"
	"math"
)

type ll int64

// Global variables
var n int
var a [50]int
var p int
var b, c int

// Function to calculate permutations nPr
func nPr(n, r ll) ll {
	res := ll(1)
	// Calculate nPr using the formula n! / (n - r)!
	for i := ll(0); i < r; i++ {
		res *= (n - i) // Multiply by (n - i) for r times
	}
	return res // Return the result
}

// Function to calculate combinations nCr
func nCr(n, r ll) ll {
	res := 1.0
	// Calculate nCr using an iterative approach to avoid large intermediate values
	for i := ll(0); i < r; i++ {
		res *= float64(n - i) // Multiply by (n - i)
		res /= float64(i + 1) // Divide by (i + 1) to account for r!
	}
	return ll(res) // Return the result as long long
}

func main() {
	// Input the number of elements and the parity flag
	fmt.Scan(&n, &p)

	// Read the array elements and count even and odd numbers
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Input each element
		if a[i]%2 == 0 {
			b++ // Increment even count
		} else {
			c++ // Increment odd count
		}
	}

	// Initialize sums for combinations
	var bsum, csum ll
	// Calculate the total subsets of even numbers (2^b)
	bsum = ll(math.Pow(2, float64(b)))

	// Calculate combinations of odd numbers based on the parity flag
	if p == 0 {
		// If p is 0, count combinations of even counts of odd numbers
		for i := 0; i <= c; i++ {
			if i%2 == 0 {
				csum += nCr(ll(c), ll(i)) // Add combinations for even i
			}
		}
	} else {
		// If p is 1, count combinations of odd counts of odd numbers
		for i := 0; i <= c; i++ {
			if i%2 == 1 {
				csum += nCr(ll(c), ll(i)) // Add combinations for odd i
			}
		}
	}

	// Calculate the final answer as the product of bsum and csum
	ans := bsum * csum
	// Output the result
	fmt.Println(ans)
}

// <END-OF-CODE>
