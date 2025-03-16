
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input and split it into an array of strings
	scanner.Scan()
	inp := strings.Split(scanner.Text(), "")

	// Parse the first two elements of the input array as integers n and m
	n, _ := strconv.Atoi(inp[0])
	m, _ := strconv.Atoi(inp[1])

	// Initialize an array to hold the resulting strings
	ans := make([]string, n)

	// Loop through each of the n lines of input
	for i := 0; i < n; i++ {
		// Read the current line of input
		scanner.Scan()
		str := scanner.Text()

		// Create a StringBuilder to construct the output for the current line
		temp := strings.Builder{}

		// Loop through each character in the current line
		for j := 0; j < m; j++ {
			// Check if the character is a '-'
			if str[j] == '-' {
				// Append '-' to the StringBuilder if it is
				temp.WriteString("-")
			} else {
				// If the character is not '-', determine whether to append 'W' or 'B'
				if (i+j)%2 == 1 {
					// Append 'W' for odd indices
					temp.WriteString("W")
				} else {
					// Append 'B' for even indices
					temp.WriteString("B")
				}
			}
		}

		// Store the constructed string in the ans array
		ans[i] = temp.String()
	}

	// Output the resulting strings line by line
	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

