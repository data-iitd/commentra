package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input
	firstLine, _ := reader.ReadString('\n')
	inp := strings.Fields(firstLine)

	// Parse the first two elements of the array into integers n and m
	n, _ := strconv.Atoi(inp[0])
	m, _ := strconv.Atoi(inp[1])

	// Create a slice ans of size n to store the processed strings
	ans := make([]string, n)

	// Iterate through each string in the input
	for i := 0; i < n; i++ {
		str, _ := reader.ReadString('\n')
		str = strings.TrimSpace(str) // Remove any trailing newline characters
		var temp strings.Builder // Initialize an empty strings.Builder

		// Iterate through each character in the string
		for j := 0; j < m; j++ {
			if str[j] == '-' { // If the character is a '-'
				temp.WriteString("-") // Append a '-' character to temp
			} else {
				if (i+j)%2 == 1 { // If the index i + j is odd
					temp.WriteString("W") // Append 'W' character to temp
				} else {
					temp.WriteString("B") // Otherwise, append 'B' character to temp
				}
			}
		}

		// Store the final string in the ans slice using the index i
		ans[i] = temp.String()
	}

	// Iterate through each string in the ans slice and print it to the standard output stream
	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

// <END-OF-CODE>
