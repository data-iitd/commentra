package main

import (
	"fmt"
)

func main() {
	var n int // Declare an integer variable 'n' to store the number of strings
	fmt.Scan(&n) // Read the number of strings from the standard input

	// Declare a slice: 'cnt' to store the count of each character
	cnt := make([]int, 26)
	for i := range cnt {
		cnt[i] = 1 // Initialize each count to 1
	}

	// Read the strings from the standard input and update the count slice accordingly
	for i := 0; i < n; i++ {
		var char byte // Declare a byte variable to store the character
		fmt.Scanf("%c\n", &char) // Read a character from the standard input
		cnt[char-'a']++ // Increment the count of the character in the 'cnt' slice
	}

	// Calculate the answer using the count slice
	ans := int64(1) // Initialize the answer to 1
	for i := 0; i < 26; i++ { // Iterate through all the characters from 'a' to 'z'
		ans *= int64(cnt[i]) // Multiply the answer with the count of the current character
	}

	// Calculate the final answer by subtracting 1 from the initial answer
	ans--

	// Print the final answer to the standard output
	fmt.Println(ans)
}

// <END-OF-CODE>
