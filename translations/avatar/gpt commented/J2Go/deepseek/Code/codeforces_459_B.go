package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)
	
	// Create a PrintWriter object to output results to the standard output stream
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()
	
	// Read the number of elements from input
	scanner.Scan()
	N := 0
	fmt.Sscan(scanner.Text(), &N)
	
	// Initialize an array to hold the input integers
	A := make([]int, N)
	
	// Read N integers from input and store them in the array A
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &A[i])
	}
	
	// Sort the array A to easily find the minimum and maximum values
	sort.Ints(A)
	
	// Identify the minimum and maximum values in the sorted array
	min := A[0]
	max := A[N - 1]
	
	// Initialize counters for occurrences of min and max values
	var mins, maxs int64 = 0, 0
	
	// Count how many times the minimum and maximum values occur in the array
	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}
	
	// If all elements are the same (min equals max)
	if min == max {
		// Calculate the difference (which is 0) and the number of ways to choose 2 from mins
		fmt.Fprintln(stdout, (max - min), mins * (mins - 1) / 2)
	} else {
		// Calculate the difference and the product of occurrences of min and max
		fmt.Fprintln(stdout, (max - min), mins * maxs)
	}
}
