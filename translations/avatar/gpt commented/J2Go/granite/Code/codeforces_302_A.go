
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the array and the number of queries
	n, _ := strconv.Atoi(read(reader))
	k, _ := strconv.Atoi(read(reader))

	// Initialize an array to hold the input values
	arr := make([]int, n)

	// Populate the array with input values
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(read(reader))
	}

	// Counters for the number of 1s (o) and 0s (e) in the array
	o, e := 0, 0
	for _, v := range arr {
		if v == 1 {
			o++
		} else {
			e++
		}
	}

	// Process each query
	for i := 0; i < k; i++ {
		// Read the left and right indices for the current query
		l, _ := strconv.Atoi(read(reader))
		r, _ := strconv.Atoi(read(reader))

		// Check if the number of elements in the range is odd
		if (r-l+1)%2 == 1 {
			fmt.Println(0) // If odd, print "0"
		} else {
			// If even, check if we can form a valid pair of 1s and 0s
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				fmt.Println(1) // Print "1" if valid pairs can be formed
			} else {
				fmt.Println(0) // Otherwise, print "0"
			}
		}
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

