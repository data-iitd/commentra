package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the values of n and x
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n, &x)

	// Read the list of integers a
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	// Initialize a 2D list b with None values
	// b[j][i] will store the minimum value in the circular array from i to j
	b := make([][]int, n)
	for i := 0; i < n; i++ {
		b[i] = make([]int, n)
	}

	// Calculate the minimum value in a circular array for each starting position i and ending position j
	for i := 0; i < n; i++ {
		m := a[i]  // Initialize m with the current element
		for j := 0; j < n; j++ {
			k := i - j  // Calculate the index in the circular array
			if k < 0 {
				k += n  // Adjust k if it is negative
			}
			m = min(m, a[k])  // Update m with the minimum value in the circular array
			b[j][i] = m  // Store the minimum value in b
	}

	// Find the minimum sum of each row in b plus x times the row index
	m := 10 ** 15
	for i, j := range b {
		m = min(m, sum(j) + x * i)
	}

	// Print the minimum value found
	fmt.Println(m)
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

