package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const N = 200 + 10 // Define a constant for the maximum size of the arrays

var f [N]int    // Array to store the failure function values
var b [N]rune   // Array to store the concatenated strings

// Function to compute the failure function for the KMP algorithm
func getFail(b []rune, m int) {
	j := 0 // Initialize j to track the length of the previous longest prefix suffix
	f[0], f[1] = 0, 0 // Base cases for the failure function

	// Loop through the string to fill the failure function
	for i := 2; i <= m; i++ {
		// Adjust j until we find a match or j becomes 0
		for j > 0 && b[j+1] != b[i] {
			j = f[j]
		}
		// If there is a match, increment j
		if b[j+1] == b[i] {
			j++
		}
		// Set the failure function value for the current position
		f[i] = j
	}
}

func main() {
	// Create an input reader
	reader := bufio.NewReader(os.Stdin)

	// Read the length of the strings
	var n int
	fmt.Fscan(reader, &n)

	// Read the two strings
	var s1, str string
	fmt.Fscan(reader, &s1, &str)

	cnt := 0

	// Concatenate the second string into the character array
	for _, ch := range str {
		cnt++
		b[cnt] = ch
	}
	// Concatenate the first string into the character array
	for _, ch := range s1 {
		cnt++
		b[cnt] = ch
	}

	// Compute the failure function for the concatenated strings
	getFail(b[:], cnt)

	// Calculate the length of the longest prefix which is also a suffix
	len := min(f[cnt], min(n, n))
	// Output the result based on the calculated length
	fmt.Println(2*n - len)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
