package main

import (
	"fmt"
)

func main() {
	var s string // Declare a string variable 's' to store the input string
	fmt.Scan(&s) // Read a string from the standard input and store it in 's'
	n := len(s)  // Get the size of the string 's' and store it in 'n'
	v := make([]int, 26) // Declare and initialize an integer slice 'v' of size 26 with zeroes

	// Read each character of the string 's' and increment the corresponding index in slice 'v'
	for i := 0; i < n; i++ {
		v[s[i]-'a']++ // Increment the index 's[i] - 'a' in slice 'v'
	}

	// Initialize answer string to "Yes"
	ans := "Yes"

	// Check if all elements in slice 'v' are even
	for i := 0; i < 26; i++ {
		if v[i]%2 != 0 { // Check if the current index in slice 'v' is odd
			ans = "No" // If so, set the answer string to "No"
			break // Exit the loop as soon as an odd number is found
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
