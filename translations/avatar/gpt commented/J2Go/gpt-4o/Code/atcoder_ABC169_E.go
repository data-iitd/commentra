package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Define a constant number for modulo operations
	const num = 998244353

	// Initialize BufferedReader to read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of pairs (n) from input
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1])

	// Create slices to store the two sets of integers
	ai := make([]int, 0, n)
	bi := make([]int, 0, n)

	// Read n pairs of integers from input
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		var a, b int
		fmt.Sscanf(line, "%d %d", &a, &b)
		ai = append(ai, a)
		bi = append(bi, b)
	}

	// Sort both slices to prepare for median calculation
	sort.Ints(ai)
	sort.Ints(bi)

	// Check if the number of elements is odd
	if n%2 == 1 {
		// Calculate the result for odd n using the median values
		fmt.Println(bi[n/2] - ai[n/2] + 1)
	} else {
		// Calculate the average of the two middle values for even n
		b := float64(ai[n/2]+ai[n/2-1]) / 2
		c := float64(bi[n/2]+bi[n/2-1]) / 2
		// Calculate the result for even n and print it
		fmt.Println(int(2*(c-b) + 1))
	}
}

// <END-OF-CODE>
