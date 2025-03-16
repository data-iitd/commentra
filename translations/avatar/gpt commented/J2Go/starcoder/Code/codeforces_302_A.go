package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array and the number of queries
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	// Initialize an array to hold the input values
	arr := make([]int, n)

	// Populate the array with input values
	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i], _ = strconv.Atoi(scanner.Text())
	}

	// Initialize a string buffer to store the results of the queries
	res := strings.Builder{}

	// Counters for the number of 1s (o) and 0s (e) in the array
	o := 0
	e := 0

	// Count the number of 1s and 0s in the array
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++
		} else {
			e++
		}
	}

	// Process each query
	for i := 0; i < k; i++ {
		// Read the left and right indices for the current query
		scanner.Scan()
		l, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		r, _ := strconv.Atoi(scanner.Text())

		// Check if the number of elements in the range is odd
		if (r-l+1)%2 == 1 {
			res.WriteString("0\n") // If odd, append "0" to results
		} else {
			// If even, check if we can form a valid pair of 1s and 0s
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				res.WriteString("1\n") // Append "1" if valid pairs can be formed
			} else {
				res.WriteString("0\n") // Otherwise, append "0"
			}
		}
	}

	// Output the results of all queries
	fmt.Println(res.String())
}

