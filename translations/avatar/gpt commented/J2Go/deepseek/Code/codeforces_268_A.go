package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Reading the number of elements (n) from the user
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	
	// Initializing a variable to store the result of matching elements
	var result int

	// Creating two arrays to hold the input values
	h := make([]int, n) // Array to store the first set of integers
	g := make([]int, n) // Array to store the second set of integers

	// Reading n integers into the first array (h)
	for i := 0; i < n; i++ {
		scanner.Scan()
		h[i], _ = strconv.Atoi(scanner.Text()) // Storing input in array h
	}

	// Reading n integers into the second array (g)
	for i := 0; i < n; i++ {
		scanner.Scan()
		g[i], _ = strconv.Atoi(scanner.Text()) // Storing input in array g
	}

	// Comparing each element of array h with each element of array g
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// If a match is found, increment the result counter
			if h[i] == g[j] {
				result++ // Incrementing the count of matches
			}
		}
	}

	// Outputting the total number of matches found
	fmt.Println(result)
}
