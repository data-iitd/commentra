
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input values: n (number of elements) and x (a multiplier)
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	x, _ := strconv.Atoi(read(reader))

	// Read the list of integers 'a' from input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(read(reader))
	}

	// Initialize a 2D list 'b' with None values to store minimum values
	b := make([][]int, n)
	for i := 0; i < n; i++ {
		b[i] = make([]int, n)
	}

	// Fill the 2D list 'b' with minimum values from 'a'
	for i := 0; i < n; i++ {
		m := a[i] // Start with the current element
		for j := 0; j < n; j++ {
			k := i - j // Calculate the index to wrap around
			if k < 0 {
				k += n // Wrap around if index is negative
			}
			m = min(m, a[k]) // Update m to be the minimum value found
			b[j][i] = m      // Store the minimum value in the 2D list 'b'
		}
	}

	// Initialize a large value for comparison
	m := 1000000000
	// Calculate the minimum sum of elements in each row of 'b' plus the weighted index
	for i, j := range b {
		m = min(m, sum(j)+x*i) // Update m with the minimum found
	}

	// Print the final minimum value
	fmt.Println(m)
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sum(a []int) int {
	s := 0
	for _, v := range a {
		s += v
	}
	return s
}

