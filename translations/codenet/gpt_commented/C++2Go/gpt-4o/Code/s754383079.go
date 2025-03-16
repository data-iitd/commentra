package main

import (
	"fmt"
	"math"
)

const M = 1010

func main() {
	var a [M]rune
	var b [M]rune
	var n, m int
	ans := M + 10

	// Read the first string into array 'a'
	fmt.Scanf("%s", &a[1])
	// Calculate the length of the first string
	n = len(a[1:])

	// Read the second string into array 'b'
	fmt.Scanf("%s", &b[1])
	// Calculate the length of the second string
	m = len(b[1:])

	// Iterate over all possible starting positions in 'a' where 'b' can fit
	for i := 1; i+m-1 <= n; i++ {
		// Initialize a variable to count the number of mismatches
		sum := 0

		// Compare the substring of 'a' with 'b' character by character
		for j := 1; j <= m; j++ {
			// Increment the mismatch count if characters do not match
			if a[i+j-1] != b[j] {
				sum++
			}
		}

		// Update the minimum number of mismatches found
		ans = int(math.Min(float64(ans), float64(sum)))
	}

	// Output the minimum number of mismatches
	fmt.Println(ans)
}

// <END-OF-CODE>
