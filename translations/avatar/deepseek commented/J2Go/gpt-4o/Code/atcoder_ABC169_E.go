package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Declare and initialize a constant integer
	const num = 998244353

	// Create a BufferedReader object to read input from the standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements 'n' from the input
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1]) // Convert string to integer

	// Create slices to store the pairs of integers
	ai := make([]int, n)
	bi := make([]int, n)

	// Read the pairs of integers from the input and store them in the slices
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		var a, b int
		fmt.Sscanf(line, "%d %d", &a, &b)
		ai[i] = a
		bi[i] = b
	}

	// Sort both slices
	sort.Ints(ai)
	sort.Ints(bi)

	// Check if 'n' is odd or even
	if n%2 == 1 {
		// If 'n' is odd, calculate the range
		midIndex := n / 2
		fmt.Println(bi[midIndex] - ai[midIndex] + 1)
	} else {
		// If 'n' is even, calculate the range
		midIndex := n / 2
		b := float64(ai[midIndex]+ai[midIndex-1]) / 2
		c := float64(bi[midIndex]+bi[midIndex-1]) / 2
		fmt.Println(int(2*(c-b) + 1))
	}
}

// <END-OF-CODE>
