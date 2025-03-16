
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Macro definitions for convenience
const (
	MOD = 100000007 // Definition of modulus for large number calculations
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(reader, "%d\n", &n) // Input the number of characters

	// Initialize a slice to count occurrences of each character (a-z)
	cnt := make([]int, 26) // Start with 0 to account for the multiplication later
	s := make([]byte, n) // Slice to store the input characters

	// Read characters and count their occurrences
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%c", &s[i]) // Input each character
		cnt[s[i]-'a']++ // Increment the count for the corresponding character
	}

	ans := cnt[0] // Initialize answer with the count of 'a'

	// Calculate the product of counts for all characters from 'b' to 'z'
	for i := 1; i < 26; i++ {
		ans *= cnt[i] // Multiply the current answer by the count of the character
		ans %= MOD // Take modulo to prevent overflow
	}

	// Output the final result, subtracting 1 to exclude the empty product case
	fmt.Println(ans - 1) // End of the program
}

