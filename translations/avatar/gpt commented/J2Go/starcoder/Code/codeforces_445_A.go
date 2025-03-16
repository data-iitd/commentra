package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input.
	line, _ := reader.ReadString('\n')

	// Split the input line into an array of strings.
	inp := strings.Split(line, "")

	// Parse the first two elements of the input array as integers.
	n, _ := strconv.Atoi(inp[0])
	m, _ := strconv.Atoi(inp[1])

	// Initialize an array to hold the resulting strings.
	ans := make([]string, n)

	// Loop through each of the n lines of input.
	for i := 0; i < n; i++ {
		// Read the current line of input.
		line, _ := reader.ReadString('\n')

		// Initialize a string builder to construct the output for the current line.
		temp := strings.Builder{}

		// Loop through each character in the current line.
		for j := 0; j < m; j++ {
			// Check if the character is a '-'.
			if line[j] == '-' {
				// Append '-' to the string builder if it is.
				temp.WriteString("-")
			} else {
				// If the character is not '-', determine whether to append 'W' or 'B'.
				if (i+j)%2 == 1 {
					// Append 'W' for odd indices.
					temp.WriteString("W")
				} else {
					// Append 'B' for even indices.
					temp.WriteString("B")
				}
			}
		}

		// Store the constructed string in the ans array.
		ans[i] = temp.String()
	}

	// Output the resulting strings line by line.
	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

