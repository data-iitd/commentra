package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	
	// Initialize arrays to store the elements
	h := make([]int, n)
	g := make([]int, n)
	
	// Read n pairs of integers from the standard input
	for i := 0; i < n; i++ {
		scanner.Scan()
		h[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		g[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Initialize the result variable to 0
	result := 0
	
	// Iterate through each element in array h
	for i := 0; i < n; i++ {
		// Compare each element in array h with each element in array g
		for j := 0; j < n; j++ {
			if h[i] == g[j] {
				// If a match is found, increment the result
				result++
			}
		}
	}
	
	// Print the value of result
	fmt.Println(result)
}
