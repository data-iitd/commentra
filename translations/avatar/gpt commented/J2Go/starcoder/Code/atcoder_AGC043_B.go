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
	m := n - 1 // Calculate the last index of the string
	ans := 0 // Initialize the answer variable
	
	// Iterate through each character in the string
	for i := 0; i < n; i++ {
		// Check if the current character matches 'c' and if the bitwise AND of m and i equals i
		if s[i] == c && (m & i) == i {
			ans ^= 1 // Toggle the answer using XOR operation
		}
	}
	return ans // Return the final calculated answer
}

// Main logic to solve the problem
func main() {
	n, _ := strconv.Atoi(readLine()) // Read the integer input for the length of the string
	s := readLine() // Read the string input
	sb := strings.Builder{} // Initialize a StringBuilder to build the new string
	
	// Build a new string based on the absolute differences between adjacent characters
	for i := 1; i < n; i++ {
		sb.WriteString(string(byte(abs(int(s[i]) - int(s[i - 1]))))) // Append the absolute difference
	}
	
	// Special case when the length of the string is 2
	if n == 2 {
		fmt.Println(sb.String()[0]) // Print the first character of the new string
		return // Exit the method
	}
	
	// Convert the StringBuilder to a string
	s = sb.String() 
	
	// Check if the new string contains the character '1'
	if strings.Contains(s, "1") {
		fmt.Println(cal(s, '1')) // Calculate and print the result for character '1'
	} else {
		fmt.Println(cal(s, '2') * 2) // Calculate and print the result for character '2', multiplied by 2
	}
}

// Method to read a line of input from stdin
func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	return string(line)
}

// Method to get the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

