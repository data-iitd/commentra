package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of characters
	cnt := make([]int, 26) // Initialize a slice to count occurrences of each letter
	for i := range cnt {
		cnt[i] = 1 // Start with 1 for each letter
	}

	var s []rune = make([]rune, n) // Slice to store the characters
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i]) // Read each character
		cnt[s[i]-'a']++ // Increment the count for the corresponding letter
	}

	ans := int64(cnt[0]) // Initialize the answer with the count of the first letter
	const MOD = 1e9 + 7
	for i := 1; i < 26; i++ { // Loop through the counts of other letters
		ans *= int64(cnt[i]) // Multiply the answer by the count of the current letter
		ans %= int64(MOD) // Take the modulo to prevent overflow
	}

	fmt.Println(ans - 1) // Output the result, subtracting 1 because we don't count the empty set
}

// <END-OF-CODE>
