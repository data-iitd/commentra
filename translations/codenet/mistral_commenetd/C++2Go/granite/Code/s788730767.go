

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Define input variables and some auxiliary variables
var n, p, b, c int
var a []int

// Function to calculate nPr (n choose r)
func nPr(n, r int) int {
	// Initialize result to 1
	res := 1
	// Iterate from 0 to r and multiply result with (n-i)
	for i := 0; i < r; i++ {
		res *= (n - i)
		// Add comment explaining what is being done
		// Multiply result with factorial of (n-i)
		// to get the value of nPr(n, r)
		//fmt.Println("Calculating nPr(", n, ", ", r, ") = ", res)
	}

	// Return the result
	return res
}

// Function to calculate nCr (n choose r)
func nCr(n, r int) int {
	// Initialize result to 1
	res := 1.0
	// Iterate from 0 to r and multiply result with (n-i) and divide by (i+1)
	for i := 0; i < r; i++ {
		res *= float64(n - i)
		res /= float64(i + 1)
		// Add comment explaining what is being done
		// Multiply result with factorial of (n-i) and divide by (i+1)
		// to get the value of nCr(n, r)
		//fmt.Println("Calculating nCr(", n, ", ", r, ") = ", res)
	}
	// Convert the double result to int and return it
	return int(res)
}

// Main function
func main() {
	// Read input values of n and p from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &n, &p)
	a = make([]int, n)
	// Initialize b and c to count the number of even and odd elements in the array a
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
		if a[i]%2 == 0 {
			b++
		} else {
			c++
		}
		// Add comment explaining what is being done
		// Read an element from the array a and check if it is even or odd
		// Increment the corresponding counter (b for even and c for odd)
	}

	// Calculate the sum of 2^b and c
	bsum := int(math.Pow(2, float64(b)))
	// Calculate the sum of nCr(c, i) for i from 0 to c
	var csum int
	if p == 0 {
		for i := 0; i <= c; i++ {
			if i%2 == 0 {
				csum += nCr(c, i)
			}
			// Add comment explaining what is being done
			// If i is even, add nCr(c, i) to csum
		}
	} else {
		for i := 0; i <= c; i++ {
			if i%2 == 1 {
				csum += nCr(c, i)
			}
			// Add comment explaining what is being done
			// If i is odd, add nCr(c, i) to csum
		}
	}

	// Multiply bsum and csum and store the result in ans
	ans := bsum * csum
	// Add comment explaining what is being done
	// Multiply bsum and csum to get the final answer

	// Print the final answer
	fmt.Println(ans)
}
