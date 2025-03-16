package main

import (
	"fmt"
)

func main() {
	var n, ans int // Declare integer n and initialize ans to 0
	var a, b, c string // Declare three strings a, b, and c
	fmt.Scan(&n) // Read the integer n from standard input
	fmt.Scan(&a, &b, &c) // Read the three strings a, b, and c from standard input
	
	// Loop through each character position up to n
	for i := 0; i < n; i++ {
		// Check if all three characters at position i are the same
		if a[i] == b[i] && b[i] == c[i] {
			// Do nothing
		} 
		// Check if any two characters at position i are the same
		else if a[i] == b[i] || b[i] == c[i] || a[i] == c[i] {
			ans++ // Increment ans by 1
		} 
		// If all three characters at position i are different
		else {
			ans += 2 // Increment ans by 2
		}
	}
	fmt.Println(ans) // Print the final value of ans
}

// <END-OF-CODE>
