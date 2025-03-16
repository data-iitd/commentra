package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the array
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements in the array: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(input)

	// Initialize a flag to indicate if a valid triplet is found
	f := 0

	// Create an array to store the input integers
	a := make([]int, n)

	// Read n integers from the input and store them in the array
	for i := 0; i < n; i++ {
		fmt.Print("Enter the ", i+1, "th element: ")
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		a[i], _ = strconv.Atoi(input)
	}

	// Initialize variables for indexing
	k := 0
	j := 0
	i := 0

	// Iterate through each element in the array
	for k = 0; k < n; k++ {
		// Store the current element to check against pairs
		t := a[k]

		// Check for pairs in the array that sum up to the current element
		for i = 0; i < n; i++ {
			for j = 0; j < n - 1; j++ {
				// Ensure we are not using the same element twice
				if i!= j && t == (a[i] + a[j]) {
					// Set the flag to indicate a valid triplet is found
					f = 1
					break
				}
			}
			// Break out of the loop if a valid pair is found
			if f == 1 {
				break
			}
		}
		// Break out of the outer loop if a valid triplet is found
		if f == 1 {
			break
		}
	}

	// Output the result: indices of the triplet or -1 if not found
	if f == 1 {
		fmt.Println(k+1, j+1, i+1)
	} else {
		fmt.Println("-1")
	}
}

