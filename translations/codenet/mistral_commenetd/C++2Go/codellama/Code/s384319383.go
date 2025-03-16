
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int // Declare an integer variable 'n' to store the number of strings
	fmt.Scan(&n) // Read the number of strings from the standard input

	// Declare two slices: 'cnt' to store the count of each character and 's' to store the strings
	cnt := make([]int, 26, 26)
	s := make([]byte, n, n)

	// Read the strings from the standard input and update the count slice accordingly
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i]) // Read a character from the standard input and store it in the 's' slice
		cnt[s[i]-'a']++ // Increment the count of the character in the 'cnt' slice
	}

	// Calculate the answer using the count slice
	ans := 1 // Initialize the answer to 1
	for i := 0; i < 26; i++ { // Iterate through all the characters from 'a' to 'z'
		ans *= cnt[i] // Multiply the answer with the count of the current character
	}

	// Calculate the final answer by subtracting 1 from the initial answer
	ans--

	// Print the final answer to the standard output
	fmt.Println(ans)
}

