package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	n int
	S []int
	T []int
)

// Function to perform binary search on the sorted array S
func binarySearch(key int) int {
	left := 0
	right := n
	var mid int
	for left < right {
		mid = (left + right) / 2
		if S[mid] == key {
			return 1
		} else if key < S[mid] {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return 0
}

func main() {
	// Read the number of elements in the sorted array S
	fmt.Scanf("%d", &n)

	// Read the elements into the sorted array S
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &S[i])
	}

	// Read the number of queries
	var q int
	fmt.Scanf("%d", &q)

	// Process each query to check if it exists in the sorted array S
	var c int
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &T[i])
		if binarySearch(T[i]) == 1 {
			c++
		}
	}

	// Output the total count of found elements
	fmt.Printf("%d\n", c)
}

