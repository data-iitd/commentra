package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize slices to store the input values
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	// Read the elements of array a
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}

	// Read the elements of array b
	for i := 1; i <= n; i++ {
		fmt.Scan(&b[i])
	}

	// Count the occurrences of each element in array b
	for i := 1; i <= n; i++ {
		num[b[i]]++
	}

	// Initialize variables to store the result
	var ss strings.Builder
	ans := 0
	st := make([]bool, n+1)

	// Iterate through the elements of array a
	for i := 1; i <= n; i++ {
		if a[i] == 1 {
			// Mark the current element as visited
			st[i] = true

			// Build the sequence of indices
			var sb strings.Builder
			x := b[i]
			var sss strings.Builder
			sss.WriteString(fmt.Sprintf("%d", i))
			sb.WriteString(" " + reverseString(sss.String()))
			s := 1

			// Continue building the sequence until a visited element or mismatch is found
			for !st[x] && num[x] == 1 && x != 0 && a[x] != 1 {
				sss.Reset()
				sss.WriteString(fmt.Sprintf("%d", x))
				sb.WriteString(" " + reverseString(sss.String()))
				st[x] = true
				x = b[x]
				s++
			}

			// Update the result if a longer sequence is found
			if s > ans {
				ans = s
				ss.Reset()
				ss.WriteString(reverseString(sb.String()))
			}
		}
	}

	// Print the result
	fmt.Println(ans)
	fmt.Println(ss.String())
}

// Helper function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
