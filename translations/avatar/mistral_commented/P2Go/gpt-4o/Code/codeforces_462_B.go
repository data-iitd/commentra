package main

import (
	"fmt"
	"sort"
)

func main() {
	// Define input variables
	var n, k int
	fmt.Scan(&n, &k)

	var s string
	fmt.Scan(&s)

	// Initialize a slice to store the count of each character
	count := make([]int, 26)

	// Iterate through each character in the string s
	for _, c := range s {
		// Increment the count of the character in the slice count
		count[c-'A']++
	}

	// Sort the count slice in descending order
	sort.Slice(count, func(i, j int) bool {
		return count[i] > count[j]
	})

	// Initialize result variable
	res := 0

	// Iterate through each character count in the slice count
	for i := 0; i < 26; i++ {
		// Check if the count of the current character is greater than or equal to k
		if count[i] >= k {
			// Calculate the result and print it
			res += k * k
			fmt.Println(res)
			// Exit the loop as we have found the required characters
			return
		}
		// Update the value of k by subtracting the count of the current character
		k -= count[i]
		// Add the square of the count of the current character to the result
		res += count[i] * count[i]
	}

	// Print the final result if no character is found with the required count
	fmt.Println(res)
}

// <END-OF-CODE>
