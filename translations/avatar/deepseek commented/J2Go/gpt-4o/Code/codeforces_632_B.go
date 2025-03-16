package main

import (
	"fmt"
)

func main() {
	// Step 1: Reading Input
	var n int
	fmt.Scan(&n) // Read the size of the array
	a := make([]int, n) // Initialize the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the elements of the array
	}

	// Step 2: Reading a String
	var s string
	fmt.Scan(&s) // Read the string

	// Step 3: Initial Sum Calculation
	var sum int64 = 0 // Initialize sum to store the sum of elements in array a where corresponding character in s is 'B'

	// Step 4: First Loop
	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += int64(a[i]) // Add the element at position i in array a to sum if the character is 'B'
		}
	}

	// Step 5: Main Logic
	ans := sum // Initialize ans with the initial sum
	sum1 := sum // Initialize sum1 for further calculations

	// First nested loop to calculate the maximum possible sum by flipping characters in s
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += int64(a[i]) // Add the element at position i in array a to sum1 if the character is 'A'
		} else {
			sum1 -= int64(a[i]) // Subtract the element at position i in array a from sum1 if the character is 'B'
		}
		if sum1 > ans {
			ans = sum1 // Update ans with the maximum value between ans and sum1
		}
	}

	// Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
	sum1 = sum // Reset sum1 to the initial sum
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += int64(a[i]) // Add the element at position i in array a to sum1 if the character is 'A'
		} else {
			sum1 -= int64(a[i]) // Subtract the element at position i in array a from sum1 if the character is 'B'
		}
		if sum1 > ans {
			ans = sum1 // Update ans with the maximum value between ans and sum1
		}
	}

	// Step 6: Output
	fmt.Println(ans) // Print the maximum sum found
}

// <END-OF-CODE>
