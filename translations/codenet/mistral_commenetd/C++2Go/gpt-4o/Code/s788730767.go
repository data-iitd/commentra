package main

import (
	"fmt"
	"math"
)

// Function to calculate nPr (n choose r)
func nPr(n, r int64) int64 {
	// Initialize result to 1
	res := int64(1)
	// Iterate from 0 to r and multiply result with (n-i)
	for i := int64(0); i < r; i++ {
		res *= (n - i)
		// Multiply result with factorial of (n-i)
		// to get the value of nPr(n, r)
		// fmt.Printf("Calculating nPr(%d, %d) = %d\n", n, r, res)
	}
	// Return the result
	return res
}

// Function to calculate nCr (n choose r)
func nCr(n, r int64) int64 {
	// Initialize result to 1
	res := float64(1)
	// Iterate from 0 to r and multiply result with (n-i) and divide by (i+1)
	for i := int64(0); i < r; i++ {
		res *= float64(n - i)
		res /= float64(i + 1)
		// Multiply result with factorial of (n-i) and divide by (i+1)
		// to get the value of nCr(n, r)
		// fmt.Printf("Calculating nCr(%d, %d) = %f\n", n, r, res)
	}
	// Convert the float64 result to int64 and return it
	return int64(res)
}

// Main function
func main() {
	var n, p int
	var a [50]int
	b, c := 0, 0

	// Read input values of n and p from the user
	fmt.Scan(&n, &p)
	// Initialize b and c to count the number of even and odd elements in the array a
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		if a[i]%2 == 0 {
			b++
		} else {
			c++
		}
		// Read an element from the array a and check if it is even or odd
		// Increment the corresponding counter (b for even and c for odd)
	}

	// Calculate the sum of 2^b and c
	bsum := int64(math.Pow(2, float64(b)))
	csum := int64(0)

	// Calculate the sum of nCr(c, i) for i from 0 to c
	if p == 0 {
		for i := int64(0); i <= int64(c); i++ {
			if i%2 == 0 {
				csum += nCr(int64(c), i)
			}
			// If i is even, add nCr(c, i) to csum
		}
	} else {
		for i := int64(0); i <= int64(c); i++ {
			if i%2 == 1 {
				csum += nCr(int64(c), i)
			}
			// If i is odd, add nCr(c, i) to csum
		}
	}

	// Multiply bsum and csum and store the result in ans
	ans := bsum * csum
	// Multiply bsum and csum to get the final answer

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
