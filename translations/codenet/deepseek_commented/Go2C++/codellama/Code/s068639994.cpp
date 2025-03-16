
#include <bits/stdc++.h>

using namespace std;

// Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// mainFn is the main logic of the program.
func mainFn() {
	// Get the number of elements in the slice.
	n := getInt()
	// Get the slice of integers.
	ls := getIntSlice(n)
	// Create a reversed version of the slice.
	lsRev := make([]int, n)
	copy(lsRev, ls)
	// Sort the original slice in ascending order.
	sort.Ints(ls)
	// Sort the reversed slice in descending order.
	sort.Sort(sort.Reverse(sort.IntSlice(lsRev)))

	// Initialize the answer variable.
	ans := 0
	// Loop through the slice to calculate the answer.
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			// Calculate p and q based on the current elements.
			p, q := min(ls[i], ls[j]), max(ls[i], ls[j])
			// Calculate x and y based on p and q.
			x, y := q-p, q+p

			// Find the left boundary using binary search.
			l := sort.Search(len(ls), func(i int) bool { return ls[i] > x })
			// Find the right boundary using binary search.
			r := n - sort.Search(len(lsRev), func(i int) bool { return lsRev[i] < y })

			// Calculate the sum of valid pairs.
			sum := r - l
			// Adjust the sum if the current indices are within the range.
			if (i >= l) && (i <= r) {
				sum--
			}
			if (j >= l) && (j <= r) {
				sum--
			}
			// Ensure the sum is not negative.
			sum = max(0, sum)
			// Add the sum to the answer.
			ans += sum
		}
	}

	// Divide the answer by 3 to get the final result.
	ans /= 3
	// Print the final answer.
	puts(ans)
}

// Helper functions to find the minimum and maximum of two integers.
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// -----------------------------------------

// Global variables for input/output operations.
var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

// main function to initialize the program.
func main() {
	// buf := 200001
	// scanner.Buffer(make([]byte, buf), buf)
	scanner.Split(bufio.ScanWords)
	mainFn()
	writer.Flush()
}

// getInt reads an integer from the standard input.
func getInt() int {
	scanner.Scan()
	i, err := strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}
	return i
}

// getIntSlice reads a slice of integers from the standard input.
func getIntSlice(n int) []int {
	is := make([]int, n)
	for i := range is {
		is[i] = getInt()
	}
	return is
}

// getString reads a string from the standard input.
func getString() string {
	scanner.Scan()
	s := scanner.Text()
	return s
}

// puts writes the arguments to the standard output.
func puts(a ...interface{}) {
	if _, err := fmt.Fprintln(writer, a...); err != nil {
		panic(err)
	}
}

