package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())

	// Initialize the array to store cumulative sums
	arr := make([]int, n)

	// Read the first element and assign it to the first index of the array
	sc.Scan()
	arr[0], _ = strconv.Atoi(sc.Text())

	// Populate the array with cumulative sums
	for i := 1; i < n; i++ {
		// Read the next integer and add it to the previous cumulative sum
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		arr[i] = x + arr[i-1]
	}

	// Read the number of queries
	sc.Scan()
	m, _ := strconv.Atoi(sc.Text())

	// Initialize the array to store the queries
	q := make([]int, m)

	// Read each query into the array
	for i := 0; i < m; i++ {
		sc.Scan()
		q[i], _ = strconv.Atoi(sc.Text())
	}

	// Process each query and print the result
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n, m) + 1)
	}
}

// Function to perform binary search on the cumulative sum array
func fun(arr []int, q int, n int, m int) int {
	res := 0 // Variable to store the result index
	i := 0   // Initialize pointers for binary search
	j := n

	// Perform binary search to find the appropriate index
	for i <= j {
		md := i + (j-i)/2 // Calculate the mid index

		// If the middle element is equal to the query, return the index
		if arr[md] == q {
			return md
		}
		// If the middle element is greater than the query, adjust the search range
		if arr[md] > q {
			res = md // Update result to the current mid index
			j = md - 1 // Move the end pointer left
		} else {
			i = md + 1 // Move the start pointer right
		}
	}

	// Return the last found index where the cumulative sum is less than the query
	return res
}

