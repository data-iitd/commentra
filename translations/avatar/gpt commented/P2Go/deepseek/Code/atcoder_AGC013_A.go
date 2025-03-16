package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a line of input and strip whitespace
func input() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read an integer from input
func INT() int {
	n, _ := strconv.Atoi(input())
	return n
}

// Function to read a list of integers from input
func MAP() []int {
	line := input()
	parts := strings.Split(line, " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a list of integers and return it as a slice
func LIST() []int {
	nums := MAP()
	return nums
}

// Function to read multiple lists of integers and return them as a slice of slices
func ZIP(n int) [][]int {
	zipped := make([][]int, n)
	for i := 0; i < n; i++ {
		zipped[i] = LIST()
	}
	return zipped
}

func main() {
	// Read the number of elements
	N := INT()

	// Read the list of integers
	A := LIST()

	// Remove consecutive duplicates from the list
	uniqueA := []int{}
	for i := 0; i < len(A); i++ {
		if i == 0 || A[i] != A[i-1] {
			uniqueA = append(uniqueA, A[i])
		}
	}

	// Update N to the new length of A after removing duplicates
	N = len(uniqueA)

	// Initialize the index and answer counter
	i := 1
	ans := 0

	// Loop through the list to count the number of peaks and valleys
	for i < N-1 {
		// Check if the current element is a peak or a valley
		if uniqueA[i-1] < uniqueA[i] && uniqueA[i] > uniqueA[i+1] || uniqueA[i-1] > uniqueA[i] && uniqueA[i] < uniqueA[i+1] {
			ans += 1 // Increment the answer for each peak/valley found
			i += 1   // Skip the next element to avoid double counting
		}
		i += 1 // Move to the next element
	}

	// Print the total count of peaks and valleys plus one
	fmt.Println(ans + 1)
}
