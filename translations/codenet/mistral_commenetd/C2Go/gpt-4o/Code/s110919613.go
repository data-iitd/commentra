package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var i, j, k, L, tmp, d, def, end, aj, max, min int

	// Infinite loop to read input
	for {
		var an [20]int
		var a1, a2 [6]int
		fmt.Scan(&an[0], &L)
		if L == 0 {
			break // Exit the loop if the input length is zero
		}

		aj = an[0]
		end = 0

		// Iterate through each number in the input array
		for k = 1; k < 20; k++ {
			// Iterate through each digit in the number from right to left
			for i := L - 1; i >= 0; i-- {
				a1[i] = aj % 10
				a2[i] = aj % 10
				aj /= 10
			}
			// Sort the digits in both arrays in ascending order
			for i := 1; i < L; i++ {
				for j := 1; j < L; j++ {
					if a1[j-1] < a1[j] { // Swap adjacent digits if they are in the wrong order
						a1[j-1], a1[j] = a1[j], a1[j-1]
					}
					if a2[j-1] > a2[j] { // Swap adjacent digits if they are in the wrong order
						a2[j-1], a2[j] = a2[j], a2[j-1]
					}
				}
			}
			// Calculate the difference between the two numbers
			d = 1
			max = 0
			min = 0
			for i := L - 1; i >= 0; i-- {
				max += (a1[i] % 10) * d
				min += (a2[i] % 10) * d
				d *= 10
			}
			def = max - min // Store the difference in a variable

			// Check if the difference has already been encountered in the array 'an'
			for i = 0; i < k; i++ {
				if def == an[i] { // If a match is found, print the result and exit the loop
					fmt.Printf("%d %d %d\n", i, def, k-i)
					end = 1
					break
				}
			}
			if end == 1 {
				break // Exit the loop if a match is found
			}
			an[k] = def // Update the array for the next iteration
			aj = def
		}
	}
}
