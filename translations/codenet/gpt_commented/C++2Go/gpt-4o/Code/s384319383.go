package main

import (
	"fmt"
)

const (
	INF = 1e9
	MOD = 1e9 + 7
)

func main() {
	var n int // Variable to store the number of characters
	fmt.Scan(&n) // Input the number of characters

	// Initialize a slice to count occurrences of each character (a-z)
	cnt := make([]int, 26) // Start with 0 to count occurrences
	for i := range cnt {
		cnt[i] = 1 // Start with 1 to account for the multiplication later
	}

	s := make([]rune, n) // Slice to store the input characters

	// Read characters and count their occurrences
	for i := 0; i < n; i++ {
		fmt.Scanf("%c\n", &s[i]) // Input each character
		cnt[s[i]-'a']++ // Increment the count for the corresponding character
	}

	ans := cnt[0] // Initialize answer with the count of 'a'

	// Calculate the product of counts for all characters from 'b' to 'z'
	for i := 1; i < 26; i++ {
		ans *= cnt[i] // Multiply the current answer by the count of the character
		ans %= int(MOD) // Take modulo to prevent overflow
	}

	// Output the final result, subtracting 1 to exclude the empty product case
	fmt.Println(ans - 1)
}

// <END-OF-CODE>
