
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements in the array
	n, _ := strconv.Atoi(read())

	// Read the elements into the array A
	A := make([]int, n)
	for i := 0; i < n; i++ {
		A[i], _ = strconv.Atoi(read())
	}

	// Read the number of queries
	q, _ := strconv.Atoi(read())

	// Process each query
	sum := 0
	for i := 0; i < q; i++ {
		// Read the key to search for
		k, _ := strconv.Atoi(read())

		// Perform binary search for the key
		if binarySearch(k, A) {
			sum++ // Increment the sum if the key is found
		}
	}

	// Output the total number of keys found in the array
	fmt.Println(sum)
}

func binarySearch(key int, A []int) bool {
	left := 0 // Initialize the left boundary of the search range
	right := len(A) // Initialize the right boundary of the search range
	mid := 0 // Variable to hold the midpoint index during the search

	// Continue searching while the left boundary is less than the right boundary
	for left < right {
		mid = (left + right) / 2 // Calculate the midpoint index
		if key == A[mid] {
			return true // If the key is found, return true
		}
		if key > A[mid] {
			left = mid + 1 // If the key is greater, search in the right half
		} else {
			right = mid // If the key is smaller, search in the left half
		}
	}
	return false // If the key is not found, return false
}

func read() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

