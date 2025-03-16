// Package main is the entry point of the program
package main

import (
	"bufio" // For reading input from standard input
	"fmt"   // For printing output
	"os"    // For reading input from files and writing output to files
	"strconv" // For converting strings to integers and back
)

// main function is the entry point of the program
func main() {
	// Read the number of test cases N from standard input
	N := nextInt()

	// Read an array h of N integers from standard input
	h := nextInts(N)

	// Initialize a dp array of size N with zeros
	dp := make([]int, N)
	for i := 0; i < N; i++ {
		dp[i] = 0
	}

	// Set the first element of dp to the absolute difference between the first and second elements of h
	dp[1] = Abs(h[0] - h[1])

	// Iterate over the array h from the second element to the last
	for i := 2; i < N; i++ {
		// Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
		dp[i] = Min([]int{dp[i - 1] + Abs(h[i] - h[i - 1]), dp[i - 2] + Abs(h[i] - h[i - 2])})
	}

	// Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
	fmt.Println(dp[N-1])
}

// Helper functions to calculate the maximum, minimum, sum, and absolute difference of integers
func Max(a []int) int {
	r := a[0]
	for i := 0; i < len(a); i++ {
		if r < a[i] {
			r = a[i]
		}
	}
	return r
}

func Min(a []int) int {
	r := a[0]
	for i := 0; i < len(a); i++ {
		if r > a[i] {
			r = a[i]
		}
	}
	return r
}

func Sum(a []int) (r int) {
	for i := range a {
		r += a[i]
	}
	return r
}

func Abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Helper function to read input from standard input as a single string
func NewScanner() func() string {
	r := bufio.NewScanner(os.Stdin)
	r.Buffer(make([]byte, 1024), int(1e+11))
	r.Split(bufio.ScanWords)
	return func() string {
		r.Scan()
		return r.Text()
	}
}

// Helper function to read a single string from standard input
func nextString() string {
	return nextReader()
}

// Helper function to read a single integer from standard input
func nextInt() int {
	v, _ := strconv.Atoi(nextReader())
	return v
}

// Helper function to read an array of N integers from standard input
func nextInts(n int) []int {
	r := make([]int, n)
	for i := 0; i < n; i++ {
		r[i] = nextInt()
	}
	return r
}
