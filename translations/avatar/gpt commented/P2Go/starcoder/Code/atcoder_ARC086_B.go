package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Set the recursion limit to a higher value to handle deep recursions
const maxDepth = 1000000000

func main() {
	// Read the number of elements
	N, _ := strconv.Atoi(readLine())

	// Read the list of integers
	a := readArray(N)

	// Initialize variables to track the maximum absolute value, its sign, and index
	maxVal := 0
	maxSign := 0
	maxIndex := -1

	// Loop through the list to find the maximum absolute value and its properties
	for i, a0 := range a {
		if a0 > maxVal {
			maxVal = a0
			maxSign = 1
			maxIndex = i
		} else if a0 < maxVal {
			maxSign = -1
			maxIndex = i
		}
	}

	// Check the sign of the maximum value and print results accordingly
	if maxSign == 0 {
		// If the maximum sign is zero, print 0
		fmt.Println(0)
	} else if maxSign == 1 {
		// If the maximum sign is positive, print the number of operations and the operations
		fmt.Println(2*N - 1)
		for i := 0; i < N; i++ {
			fmt.Println(maxIndex+1, i+1)
		}
		for i := 0; i < N-1; i++ {
			fmt.Println(i+1, i+2)
		}
	} else {
		// If the maximum sign is negative, print the number of operations and the operations
		fmt.Println(2*N - 1)
		for i := 0; i < N; i++ {
			fmt.Println(maxIndex+1, i+1)
		}
		for i := 1; i < N; i++ {
			fmt.Println(i+1, i)
		}
	}
}

// Read a single line from stdin.
func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

// Read a slice of integers from stdin.
func readArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readLine())
	}
	return a
}

