
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to calculate permutations nPr
func nPr(n, r int) int {
	res := 1
	// Calculate nPr using the formula n! / (n - r)!
	for i := 0; i < r; i++ {
		res *= (n - i) // Multiply by (n - i) for r times
	}
	return res // Return the result
}

// Function to calculate combinations nCr
func nCr(n, r int) int {
	// Using the formula nCr = nPr(n, r) / r!
	res := 1
	// Calculate nCr using an iterative approach to avoid large intermediate values
	for i := 0; i < r; i++ {
		res *= (n - i) // Multiply by (n - i)
		res /= (i + 1) // Divide by (i + 1) to account for r!
	}
	return res // Return the result
}

func main() {
	// Initialize variables
	var n, p, b, c int
	// Read input from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &n, &p)
	// Read the array elements and count even and odd numbers
	for i := 0; i < n; i++ {
		var a int
		fmt.Fscanf(reader, "%d\n", &a)
		if a%2 == 0 {
			b++ // Increment even count
		} else {
			c++ // Increment odd count
		}
	}
	// Initialize sums for combinations
	var bsum, csum int
	// Calculate the total subsets of even numbers (2^b)
	bsum = int(pow(2, float64(b)))
	// Calculate combinations of odd numbers based on the parity flag
	if p == 0 {
		// If p is 0, count combinations of even counts of odd numbers
		for i := 0; i <= c; i++ {
			if i%2 == 0 {
				csum += nCr(c, i) // Add combinations for even i
			}
		}
	} else {
		// If p is 1, count combinations of odd counts of odd numbers
		for i := 0; i <= c; i++ {
			if i%2 == 1 {
				csum += nCr(c, i) // Add combinations for odd i
			}
		}
	}
	// Calculate the final answer as the product of bsum and csum
	ans := bsum * csum
	// Output the result
	fmt.Println(ans)
}

func pow(x float64, n float64) float64 {
	if n == 0 {
		return 1
	} else if n%2 == 0 {
		return pow(x*x, n/2)
	} else {
		return x * pow(x*x, (n-1)/2)
	}
}

// End of code