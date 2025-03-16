package main

import (
	"fmt"
)

func main() {
	var N, K int
	var S string
	fmt.Scan(&N, &K, &S) // Read the first integer N, second integer K, and string S

	c1 := []rune(S) // Convert the string S to a rune slice c1
	c3 := []rune(S) // Convert the string S to a rune slice c3

	flag := false // A flag to indicate whether we are flipping
	count := 0    // A counter for the number of flips

	// Process c1 (Left to Right)
	for i := 0; i < N; i++ {
		if flag && c1[i] == 'R' { // If we are flipping and encounter 'R'
			flag = false // Reset the flag
			count++      // Increment the flip count
		}
		if count == K { // If we have made K flips, break out of the loop
			break
		}
		if c1[i] == 'L' { // If we encounter 'L'
			flag = true   // Set the flag to true
			c1[i] = 'R'   // Flip it to 'R'
		}
	}

	flag = false // Reset the flag
	count = 0    // Reset the flip count

	// Process c3 (Right to Left)
	for i := 0; i < N; i++ {
		if flag && c3[i] == 'L' { // If we are flipping and encounter 'L'
			flag = false // Reset the flag
			count++      // Increment the flip count
		}
		if count == K { // If we have made K flips, break out of the loop
			break
		}
		if c3[i] == 'R' { // If we encounter 'R'
			flag = true   // Set the flag to true
			c3[i] = 'L'   // Flip it to 'L'
		}
	}

	S1 := string(c1) // Convert the modified c1 back to a string S1
	S3 := string(c3) // Convert the modified c3 back to a string S3

	count = 1       // Initialize count for consecutive characters
	sum1 := 0      // Initialize sum for S1
	bef := S1[0]   // Initialize the previous character

	// Count consecutive characters in S1
	for i := 1; i < N; i++ {
		if S1[i] == bef { // If the current character is the same as the previous
			count++ // Increment the count
			if i == N-1 { // If it's the last character in the string
				sum1 += count - 1 // Add the count minus one to the sum
			}
		} else { // If the current character is different
			bef = S1[i] // Update the previous character
			sum1 += count - 1 // Add the count minus one to the sum
			count = 1 // Reset the count
		}
	}

	count = 1       // Reset count for consecutive characters
	sum3 := 0      // Initialize sum for S3
	bef = S3[0]    // Initialize the previous character

	// Count consecutive characters in S3
	for i := 1; i < N; i++ {
		if S3[i] == bef { // If the current character is the same as the previous
			count++ // Increment the count
			if i == N-1 { // If it's the last character in the string
				sum3 += count - 1 // Add the count minus one to the sum
			}
		} else { // If the current character is different
			bef = S3[i] // Update the previous character
			sum3 += count - 1 // Add the count minus one to the sum
			count = 1 // Reset the count
		}
	}

	// Print the maximum of the two sums
	fmt.Println(max(sum1, sum3))
}

// max function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
