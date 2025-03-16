package main

import (
	"fmt"
)

func main() {
	// Initialize an empty map named 'm'
	m := make(map[int]int)

	// Iterate through all possible indices 'i' that satisfy the condition i*200 < 5001
	for i := 0; i*200 < 5001; i++ {
		// Iterate through all possible indices 'j' that satisfy the condition j*300 < 5001
		for j := 0; j*300 < 5001; j++ {
			// Iterate through all possible indices 'k' that satisfy the condition k*500 < 5001
			for k := 0; k*500 < 5001; k++ {
				// Calculate the composite index 'w'
				w := i*200 + j*300 + k*500

				// Calculate the potential value 'p' for the given index 'w'
				p := (i/5)*5*380*80/100 + (i%5)*380 +
					(j/4)*4*550*85/100 + (j%4)*550 +
					(k/3)*3*850*88/100 + (k%3)*850

				// If the map 'm' already contains the index 'w', update its value with the minimum of the current potential value and the existing one
				if existing, found := m[w]; found {
					m[w] = min(existing, p)
				} else {
					// If the map 'm' does not contain the index 'w', add it with the current potential value as its value
					m[w] = p
				}
			}
		}
	}

	// Read integers from the standard input and print their corresponding potential values from the map 'm'
	var n int
	for {
		_, err := fmt.Scan(&n)
		if err != nil || n == 0 {
			break
		}
		fmt.Println(m[n])
	}
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
