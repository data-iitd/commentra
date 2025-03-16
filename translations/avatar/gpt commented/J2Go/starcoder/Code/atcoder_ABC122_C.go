package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for the modulo value
const mod = 1000000007

func main() {
	// Create a buffered reader to read input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of characters (n) and the number of queries (q)
	n, _ := strconv.Atoi(readLine(reader))
	q, _ := strconv.Atoi(readLine(reader))

	// Read the character array from input
	c := strings.Split(readLine(reader), "")

	// Initialize a 2D array to store the ranges for each query
	range := make([][]int, q)

	// Read the ranges for each query
	for i := 0; i < q; i++ {
		range[i] = make([]int, 2)
		range[i][0], _ = strconv.Atoi(readLine(reader))
		range[i][1], _ = strconv.Atoi(readLine(reader))
	}

	// Initialize arrays to track fragments and cumulative sums
	frag := make([]int, n + 1) // To count occurrences of "AC"
	rui := make([]int, n + 1)  // To store cumulative sums of fragments

	// Loop through the character array to count occurrences of "AC"
	for i := 2; i <= n; i++ {
		// Check if the current and previous characters form "AC"
		if c[i - 2] == "A" && c[i - 1] == "C" {
			frag[i]++ // Increment the fragment count
		}
		// Update the cumulative sum of fragments
		rui[i] = rui[i - 1] + frag[i]
	}

	// Process each query to find the number of "AC" in the specified range
	for i := 0; i < q; i++ {
		left := range[i][0]   // Get the left index of the query
		right := range[i][1]  // Get the right index of the query

		// Calculate and print the result for the current query
		fmt.Println(rui[right] - rui[left])
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

