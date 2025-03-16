package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading an integer input

	s := "" // Initializing an empty string to store binary representation

	// Converting the integer to binary representation
	for n > 0 {
		x := n % 2 // Getting the remainder when divided by 2
		n /= 2     // Dividing the number by 2
		s = fmt.Sprintf("%s%d", s, x) // Appending the remainder to the string
	}

	ans := 0 // Initializing a variable to count the number of '1's

	// Counting the number of '1's in the binary representation
	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			ans++ // Incrementing the count if the character is '1'
		}
	}

	fmt.Println(ans) // Printing the count of '1's
}

// <END-OF-CODE>
