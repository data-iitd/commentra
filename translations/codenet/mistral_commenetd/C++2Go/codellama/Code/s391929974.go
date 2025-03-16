package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables
	var n int // Number of elements in the array
	sq := make([]int, 10000) // Square array to store squares of numbers from 1 to n-1
	fr := make([]int, 5000) // Frequency array to store the frequency of each difference between squares
	com := make([]int, 0) // Vector to store unique squares
	tmp := 0 // Temporary variable

	// Start of the infinite loop
	for {
		fmt.Scan(&n) // Read the number of elements in the array from the user
		if n == 0 { // If the number is zero, break the loop
			break
		}

		// Initialize square array
		for i := 1; i < n; i++ {
			sq[i] = int(math.Pow(float64(i), 2)) % n
		}
		com = com[:0] // Clear the vector before filling it with new unique squares

		// Find unique squares and store them in the vector
		for i := 1; i < n; i++ {
			f := true // Flag to check if the square is already present in the vector
			for j := 0; j < len(com); j++ {
				if com[j] == sq[i] { // If the square is already present, set the flag to false
					f = false
					break
				}
			}
			if f { // If the square is not present, add it to the vector
				com = append(com, sq[i])
			}
		}

		// Initialize frequency array
		for i := 0; i <= (n-1)/2; i++ {
			fr[i] = 0
		}

		// Find the frequency of each difference between unique squares
		for i := 0; i < len(com); i++ {
			for j := 0; j < len(com); j++ {
				if i != j { // If the indices are not same
					tmp = com[i] - com[j] // Calculate the difference between two squares
					if tmp < 0 { // If the difference is negative, make it positive by adding n
						tmp += n
					}
					if tmp > (n-1)/2 { // If the difference is greater than half the size of the array, make it smaller by subtracting the difference from the size of the array
						tmp = n - tmp
					}
					fr[tmp]++ // Increment the frequency of the difference
				}
			}
		}

		// Print the frequency of each difference
		for i := 1; i <= (n-1)/2; i++ {
			fmt.Println(fr[i])
		}
	}
}

