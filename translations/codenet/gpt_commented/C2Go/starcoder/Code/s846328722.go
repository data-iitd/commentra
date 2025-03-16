package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to perform linear search
func linersearch(a []int, n int, key int) bool {
	i := 0
	a[n] = key
	for a[i]!= key {
		i++
	}
	return i!= n
}

func main() {
	var n, q, t, count int
	var s []int
	var i int
	var line string
	var err error

	// Read the number of elements in the array
	fmt.Scanf("%d", &n)

	// Read n elements into the array s
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &s[i])
	}

	// Read the number of queries
	fmt.Scanf("%d", &q)

	// Process each query to check if the element exists in the array
	for i = 0; i < q; i++ {
		fmt.Scanf("%d", &t) // Read the query element
		// Use linear search to check if the element t is in the array s
		if linersearch(s, n, t) {
			count++ // Increment count if found
		}
	}

	// Output the total count of found elements
	fmt.Printf("%d\n", count)
}

