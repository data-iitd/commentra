package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize slices to store input values and counts
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	// Read values into slice a
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}

	// Read values into slice b
	for i := 1; i <= n; i++ {
		fmt.Scan(&b[i])
	}

	// Count occurrences of each value in slice b
	for i := 1; i <= n; i++ {
		num[b[i]]++
	}

	// Initialize variables for tracking the longest sequence and its representation
	var ss strings.Builder
	ans := 0
	st := make([]bool, n+1)

	// Iterate through each element to find the longest valid sequence
	for i := 1; i <= n; i++ {
		// Check if the current element in a is 1
		if a[i] == 1 {
			st[i] = true // Mark this index as visited
			var sb strings.Builder
			x := b[i] // Start with the corresponding value in b
			sb.WriteString(fmt.Sprintf(" %d", i)) // Append the current index

			s := 1 // Initialize the length of the current sequence

			// Continue to build the sequence while conditions are met
			for !st[x] && num[x] == 1 && x != 0 && a[x] != 1 {
				sb.WriteString(fmt.Sprintf(" %d", x)) // Append the next index
				st[x] = true // Mark this index as visited
				x = b[x] // Move to the next index in b
				s++ // Increment the sequence length
			}

			// Update the longest sequence found if the current one is longer
			if s > ans {
				ans = s
				// Reverse the string for the longest sequence
				seq := sb.String()
				// Reverse the sequence
				reversedSeq := reverseString(seq)
				ss.Reset()
				ss.WriteString(reversedSeq) // Store the longest sequence
			}
		}
	}

	// Output the length of the longest sequence and the sequence itself
	fmt.Println(ans)
	fmt.Println(ss.String())
}

// Function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
