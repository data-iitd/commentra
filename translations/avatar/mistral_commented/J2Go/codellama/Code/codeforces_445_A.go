
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from the standard input stream using a bufio.Scanner object
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input and split it into an array of strings
	inp := strings.Split(scanner.Text(), "")

	// Parse the first two elements of the array into integers n and m
	n, _ := strconv.Atoi(inp[0])
	m, _ := strconv.Atoi(inp[1])

	// Create an array ans of size n to store the processed strings
	ans := make([]string, n)

	// Iterate through each string in the input
	for i := 0; i < n; i++ {
		// Read a string from the input
		scanner.Scan()
		str := scanner.Text()
		temp := ""

		// Iterate through each character in the string
		for j := 0; j < m; j++ {
			if str[j] == '-' { // If the character is a '-'
				temp += "-" // Append a '-' character to temp
			} else {
				if (i+j)%2 == 1 { // If the index i + j is odd
					temp += "W" // Append 'W' character to temp
				} else {
					temp += "B" // Otherwise, append 'B' character to temp
				}
			}
		}

		// Store the final string in the ans array using the index i
		ans[i] = temp
	}

	// Iterate through each string in the ans array and print it to the standard output stream
	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

