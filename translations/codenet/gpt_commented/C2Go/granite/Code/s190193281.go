
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const N = 1000000 // Maximum size for the array S
	const Q = 500000   // Maximum size for the array T

	var n, S [N]int, T [Q]int // Declare variables: n for the number of elements, S for the sorted array, T for the query array
	var i, j, q, c int         // Declare variables: i for loops, q for number of queries, c for count of found keys

	// Read the number of elements in the sorted array S
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)

	// Read the elements into the sorted array S
	for i = 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &S[i])
	}

	// Read the number of queries
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &q)

	// Process each query to check if it exists in the sorted array S
	for i = 0; i < q; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &T[i]) // Read the query element into array T
		if binarySearch(T[i], S, n) == 1 {                   // If the element is found, increment the count
			c++
		}
	}

	// Output the total count of found elements
	fmt.Println(c)
}

func binarySearch(key int, S []int, n int) int {
	var left, right, mid int // Initialize left and right pointers for the search range
	left = 0
	right = n
	for left < right { // Continue searching while the range is valid
		mid = (left + right) / 2 // Calculate the middle index
		if S[mid] == key {
			return 1 // If the key is found, return 1
		} else if key < S[mid] {
			right = mid // Narrow the search to the left half
		} else {
			left = mid + 1 // Narrow the search to the right half
		}
	}
	return 0 // If the key is not found, return 0
}

// END-OF-CODE