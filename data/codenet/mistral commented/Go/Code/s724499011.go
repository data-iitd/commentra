
package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var n int
	fmt.Scan(&n) // Read the number of elements in the string 's'
	var s []byte
	fmt.Scan(&s) // Read the string 's'
	ns := make([]int, n) // Create a slice 'ns' of length 'n' to store the color index for each character in 's'

	// Read the string 's' into 'ns'
	for i := range s {
		// Assign color index to 'ns' based on the character in 's'
		switch s[i] {
		case 'R':
			ns[i] = 0
		case 'G':
			ns[i] = 1
		case 'B':
			ns[i] = 2
		}
	}

	// Initialize 'rgb' slice with zeros
	rgb := make([][]int, n+1)
	rgb[0] = make([]int, 3) // First row of 'rgb' slice to store the total RGB values for each color
	for i := 1; i <= n; i++ {
		// Initialize each inner row of 'rgb' slice with zeros
		rgb[i] = make([]int, 3)
		for j := 0; j < 3; j++ {
			rgb[i][j] = rgb[i-1][j] // Initialize each cell with the value of the corresponding cell in the previous row
		}
		// Increment the value of the cell in the current row and column based on the color index of the previous character
		rgb[i][ns[i-1]]++
	}

	// Calculate the sum of differences between adjacent rows in 'rgb' slice
	var sum int
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			// Check if the characters in the current and next indices have different colors
			if ns[i] != ns[j] {
				// Calculate the total difference between the corresponding cells in the 'rgb' slice
				tn := 3 - ns[i] - ns[j]
				sum += rgb[n][tn] // Get the total RGB value of the last cell in the last row with the complementary color
				sum -= rgb[j+1][tn] // Subtract the total RGB value of the first cell in the next row with the complementary color

				// Check if there is a character with the same color index between the current and next indices
				k := 2*j - i
				if k < n && ns[k] == tn {
					sum-- // Decrease the sum if there is a character with the same color index between the current and next indices
				}
			}
		}
	}

	// Print the final result
	fmt.Println(sum)
	// End of the code
}