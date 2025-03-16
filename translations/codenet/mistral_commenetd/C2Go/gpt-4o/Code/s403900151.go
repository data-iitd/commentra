package main

import (
	"fmt"
)

func main() {
	var n, r, p, c int
	var a [51]int
	var b [51]int

	for {
		// Read the values of n and r from the standard input
		_, err := fmt.Scanf("%d %d", &n, &r)
		if err != nil {
			break
		}
		if n == 0 && r == 0 { // Check if both n and r are 0
			break // If yes, break out of the loop
		}

		// Initialize array a with values from 1 to n
		for i := 0; i < n; i++ {
			a[i] = i + 1
		}

		// Iterate r times
		for i := 0; i < r; i++ {
			// Read the values of p and c from the standard input
			fmt.Scanf("%d %d", &p, &c)

			// Initialize array b with elements from array a
			for j := 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}

			// Shift elements of array a to the left by p-1 positions
			for j := 0; j < p-1; j++ {
				a[n-p+j+1] = a[n-p+j]
			}

			// Copy elements from array b to the end of array a
			for j, k := n-p-c+1, 0; k < c; j, k = j+1, k+1 {
				a[j] = b[k]
			}

			// Print the last element of array a
			fmt.Println(a[n-1])
		}
	}
}
