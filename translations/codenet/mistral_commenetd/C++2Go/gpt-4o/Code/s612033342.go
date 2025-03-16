package main

import (
	"fmt"
)

func pow2(a int) int {
	ret := 1 // Initialize result to 1
	for i := 0; i < a; i++ {
		ret *= 2 // Multiply result by 2 for each iteration of the loop
	}
	return ret // Return the final result
}

func count(hw [][]int, a, b int) int {
	sum := 0 // Initialize sum to 0
	for i := 0; i < len(hw); i++ { // Iterate through each row of the 2D grid
		for j := 0; j < len(hw[0]); j++ { // Iterate through each column of the current row
			if (a&(1<<i) != 0) && (b&(1<<j) != 0) && hw[i][j] == 1 {
				sum++ // If the bits at the corresponding positions in a and b are set and the corresponding cell in the grid is 1, increment sum
			}
		}
	}
	return sum // Return the final sum
}

func main() {
	var h, w, k int // Declare variables for height, width, and target count
	fmt.Scan(&h, &w, &k) // Read input values for height, width, and target count from standard input
	hw := make([][]int, h) // Initialize 2D grid
	for i := range hw {
		hw[i] = make([]int, w) // Initialize each row of the grid
		for j := range hw[i] {
			var c byte // Declare a variable to store the current character from input
			fmt.Scanf("%c\n", &c) // Read the character from standard input
			if c == '#' {
				hw[i][j] = 1 // If the character is '#', set the corresponding cell in the grid to 1
			}
		}
	}
	sum := 0 // Initialize sum to 0
	for i := 0; i < pow2(h); i++ { // Iterate through all possible binary combinations of height
		for j := 0; j < pow2(w); j++ { // Iterate through all possible binary combinations of width
			if count(hw, i, j) == k {
				sum++ // If the number of 1's in the current combination matches the target count, increment sum
			}
		}
	}
	fmt.Println(sum) // Output the final sum to standard output
}

// <END-OF-CODE>
