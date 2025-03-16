package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading the number of elements (n) from the user
	fmt.Print("Enter the number of elements: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Initializing a variable to store the result of matching elements
	result := 0

	// Creating two arrays to hold the input values
	h := make([]int, n) // Array to store the first set of integers
	g := make([]int, n) // Array to store the second set of integers

	// Reading n integers into the first array (h)
	fmt.Print("Enter the elements of the first set: ")
	for i := 0; i < n; i++ {
		input, _ := reader.ReadString('\n')
		h[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}

	// Reading n integers into the second array (g)
	fmt.Print("Enter the elements of the second set: ")
	for i := 0; i < n; i++ {
		input, _ := reader.ReadString('\n')
		g[i], _ = strconv.Atoi(strings.TrimSpace(input))
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

