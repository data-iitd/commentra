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

	// Read the first line of input and split it into an array of strings
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")

	// Parse the first two elements of the array into integers n and m
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	// Create an array ans of size n to store the processed strings
	ans := make([]string, n)

	// Iterate through each string in the input
	for i := 0; i < n; i++ {
		// Read a string from the input
		str, _ := reader.ReadString('\n')
		str = strings.TrimSpace(str)
		var temp strings.Builder

		// Iterate through each character in the string
		for j := 0; j < m; j++ {
			if str[j] == '-' {
				// Append a '-' character to temp
				temp.WriteByte('-')
			} else {
				// If the index i + j is odd
				if (i+j)%2 == 1 {
					// Append 'W' character to temp
					temp.WriteByte('W')
				} else {
					// Otherwise, append 'B' character to temp
					temp.WriteByte('B')
				}
			}
		}

		// Store the final string in the ans array using the index i
		ans[i] = temp.String()
	}

	// Iterate through each string in the ans array and print it to the standard output stream
	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

