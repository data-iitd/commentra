package main

import (
	"fmt"
	"math"
)

// Function to calculate 2 raised to the power of 'a'
func pow2(a int) int {
	ret := 1 // Initialize result to 1
	for i := 0; i < a; i++ {
		ret *= 2 // Multiply by 2, 'a' times
	}
	return ret // Return the result
}

// Function to count the number of '1's in the hw matrix based on the bit patterns of 'a' and 'b'
func count(hw [][]int, a, b int) int {
	sum := 0 // Initialize sum to count the valid positions
	// Iterate through each row of the hw matrix
	for i := 0; i < len(hw); i++ {
		// Iterate through each column of the hw matrix
		for j := 0; j < len(hw[0]); j++ {
			// Check if the i-th bit of 'a' and the j-th bit of 'b' are set, and if hw[i][j] is 1
			if a>>i&1 == 1 && b>>j&1 == 1 && hw[i][j] == 1 {
				sum++
			}
		}
	}
	return sum // Return the total count of valid positions
}

func main() {
	// Read the dimensions of the matrix and the target count 'k'
	var h, w, k int
	fmt.Scanf("%d %d %d\n", &h, &w, &k)

	hw := make([][]int, h) // Initialize a 2D vector with dimensions h x w filled with 0
	for i := 0; i < h; i++ {
		hw[i] = make([]int, w)
	}

	// Read the matrix input
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			var c byte
			fmt.Scanf("%c\n", &c) // Read each character
			// If the character is '#', mark it as 1 in the hw matrix
			if c == '#' {
				hw[i][j] = 1
			}
		}
	}

	sum := 0 // Initialize sum to count the valid configurations
	// Iterate through all possible combinations of rows (2^h)
	for i := 0; i < pow2(h); i++ {
		// Iterate through all possible combinations of columns (2^w)
		for j := 0; j < pow2(w); j++ {
			// If the count of '1's matches the target 'k', increment the sum
			if count(hw, i, j) == k {
				sum++
			}
		}
	}

	fmt.Println(sum) // Output the total count of valid configurations
}

