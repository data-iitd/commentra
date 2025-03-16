package main

import (
	"fmt"
)

func main() {
	// Read the integer N (length of the string) and K (number of changes allowed)
	var N, K int
	fmt.Scan(&N, &K)

	// Read the string S
	var S string
	fmt.Scan(&S)

	// Convert the string S into a slice of runes for manipulation
	c1 := []rune(S)
	c3 := []rune(S)

	// Initialize a flag to track changes and a count for 'R' occurrences
	flag := false
	count := 0

	// First pass: Change 'L' to 'R' up to K times
	for i := 0; i < N; i++ {
		// If the flag is set and the current character is 'R', increment count and reset flag
		if flag && c1[i] == 'R' {
			flag = false
			count++
		}
		// Break the loop if K changes have been made
		if count == K {
			break
		}
		// If the current character is 'L', set the flag and change 'L' to 'R'
		if c1[i] == 'L' {
			flag = true
			c1[i] = 'R'
		}
	}

	// Reset flag and count for the second pass
	flag = false
	count = 0

	// Second pass: Change 'R' to 'L' up to K times
	for i := 0; i < N; i++ {
		// If the flag is set and the current character is 'L', increment count and reset flag
		if flag && c3[i] == 'L' {
			flag = false
			count++
		}
		// Break the loop if K changes have been made
		if count == K {
			break
		}
		// If the current character is 'R', set the flag and change 'R' to 'L'
		if c3[i] == 'R' {
			flag = true
			c3[i] = 'L'
		}
	}

	// Initialize variables to count consecutive characters in S1
	count = 1
	sum1 := 0
	bef := c1[0]

	// Count the number of consecutive characters in S1
	for i := 1; i < N; i++ {
		if c1[i] == bef {
			count++
			// If it's the last character, add the count to sum1
			if i == N-1 {
				sum1 += count - 1
			}
		} else {
			bef = c1[i]
			sum1 += count - 1
			count = 1
		}
	}

	// Reset count and initialize variables to count consecutive characters in S3
	count = 1
	sum3 := 0
	bef = c3[0]

	// Count the number of consecutive characters in S3
	for i := 1; i < N; i++ {
		if c3[i] == bef {
			count++
			// If it's the last character, add the count to sum3
			if i == N-1 {
				sum3 += count - 1
			}
		} else {
			bef = c3[i]
			sum3 += count - 1
			count = 1
		}
	}

	// Output the maximum of the two sums calculated from S1 and S3
	fmt.Println(max(sum1, sum3))
}

// max function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
