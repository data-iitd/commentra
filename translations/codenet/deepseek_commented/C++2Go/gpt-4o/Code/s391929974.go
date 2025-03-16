package main

import (
	"fmt"
)

func main() {
	var n int
	sq := make([]int, 10000) // Declare slice to store squares
	fr := make([]int, 5000)  // Declare slice to store frequencies
	com := []int{}           // Declare slice to store unique squares

	for {
		fmt.Scan(&n) // Read input integer n
		if n == 0 {
			break // Break the loop if n is 0
		}

		for i := 1; i < n; i++ {
			sq[i] = (i * i) % n // Calculate squares modulo n
		}
		com = com[:0] // Clear the slice com to store new unique squares

		for i := 1; i < n; i++ { // Find unique squares modulo n
			f := true // Flag to check if the square is unique
			for j := 0; j < len(com); j++ {
				if com[j] == sq[i] { // Check if the square is already in com
					f = false // Set flag to false if not unique
					break      // Break the loop if not unique
				}
			}
			if f {
				com = append(com, sq[i]) // Add unique square to com if flag is true
			}
		}

		for i := 0; i <= (n-1)/2; i++ {
			fr[i] = 0 // Initialize frequency array
		}

		for i := 0; i < len(com); i++ { // Calculate differences between unique squares
			for j := 0; j < len(com); j++ {
				if i != j { // Avoid comparing a square with itself
					tmp := com[i] - com[j] // Calculate difference
					if tmp < 0 {
						tmp += n // Adjust if tmp is negative
					}
					if tmp > (n-1)/2 {
						tmp = n - tmp // Adjust if tmp is greater than half of n
					}
					fr[tmp]++ // Increment the count for the difference
				}
			}
		}

		for i := 1; i <= (n-1)/2; i++ {
			fmt.Println(fr[i]) // Output the frequencies
		}
	}
}

// <END-OF-CODE>
