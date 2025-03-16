package main

import (
	"fmt"
)

func main() {
	for {
		var an [20]int
		var a1, a2 [6]int
		var L int
		fmt.Scan(&an[0], &L)
		if L == 0 {
			break // If L is 0, break out of the loop
		}

		aj := an[0]
		end := 0
		for k := 1; k < 21; k++ {
			for i := L - 1; i >= 0; i-- {
				a1[i] = aj % 10
				a2[i] = aj % 10 // Initialize a1 and a2 with the digits of aj
				aj /= 10
			}
			// Sort a1 in ascending order
			for i := 1; i < L; i++ {
				for j := 1; j < L; j++ {
					if a1[j-1] < a1[j] {
						a1[j-1], a1[j] = a1[j], a1[j-1]
					}
					if a2[j-1] > a2[j] {
						a2[j-1], a2[j] = a2[j], a2[j-1]
					}
				}
			}
			d := 1
			max, min := 0, 0
			for i := L - 1; i >= 0; i-- {
				max += (a1[i] % 10) * d // Calculate max by combining sorted digits
				min += (a2[i] % 10) * d // Calculate min by combining sorted digits
				d *= 10
			}
			def := max - min // Calculate the difference def
			for i := 0; i < k; i++ {
				if def == an[i] { // Check if def has been seen before
					fmt.Printf("%d %d %d\n", i, def, k-i) // Print the index, def, and steps taken
					end = 1
					break // Set end to 1 to break out of the loop
				}
			}
			if end == 1 {
				break // If end is 1, break out of the loop
			}
			an[k] = def // Add def to an
			aj = def    // Update aj
		}
	}
}

// <END-OF-CODE>
