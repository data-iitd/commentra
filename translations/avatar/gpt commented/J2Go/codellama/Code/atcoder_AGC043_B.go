
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Method to calculate a specific value based on the input string and character
func cal(s string, c byte) int {
	n := len(s) // Get the length of the string
	m := n - 1  // Calculate the last index of the string
	ans := 0    // Initialize the answer variable

	// Iterate through each character in the string
	for i := 0; i < n; i++ {
		// Check if the current character matches 'c' and if the bitwise AND of m and i equals i
		if s[i] == c && (m&i) == i {
			ans ^= 1 // Toggle the answer using XOR operation
		}
	}
	return ans // Return the final calculated answer
}

// Main logic to solve the problem
func solve() {
	var n int // Read the integer input for the length of the string
	fmt.Scan(&n)
	s := "" // Read the string input
	fmt.Scan(&s)
	sb := "" // Initialize a StringBuilder to build the new string

	// Build a new string based on the absolute differences between adjacent characters
	for i := 1; i < n; i++ {
		sb += strconv.Itoa(int(math.Abs(float64(s[i]) - float64(s[i-1])))) // Append the absolute difference
	}

	// Special case when the length of the string is 2
	if n == 2 {
		fmt.Println(sb[0]) // Print the first character of the new string
		return // Exit the method
	}

	// Convert the StringBuilder to a string
	s = sb

	// Check if the new string contains the character '1'
	if strings.Contains(s, "1") {
		fmt.Println(cal(s, '1')) // Calculate and print the result for character '1'
	} else {
		fmt.Println(cal(s, '2') * 2) // Calculate and print the result for character '2', multiplied by 2
	}
}

// Main method to execute the program
func main() {
	solve() // Call the solve method
}

