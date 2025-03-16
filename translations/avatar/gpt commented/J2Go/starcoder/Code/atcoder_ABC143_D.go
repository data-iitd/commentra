package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of integers to be processed
	N, _ := strconv.Atoi(scanner.Text())

	// Initialize a list to store the integers
	L := make([]int, N)

	// Read N integers from input and add them to the list
	for i := 0; i < N; i++ {
		L[i], _ = strconv.Atoi(scanner.Text())
	}

	// Sort the list of integers in ascending order
	sort.Ints(L)

	// Initialize a counter to keep track of valid pairs
	count := 0

	// Iterate through each pair of integers in the sorted list
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			// Get the current pair of integers
			a := L[i]
			b := L[j]

			// Find the number of integers that can form a valid triplet with a and b
			res := find(L, j+1, a+b)

			// Increment the count by the number of valid triplets found
			count = count + res
		}
	}

	// Output the total count of valid triplets
	fmt.Println(count)
}

// Method to find the count of integers in the list that can form a valid triplet
func find(li []int, from int, target int) int {
	low := from
	upp := len(li) - 1

	// Calculate the mid index based on the current low and upper bounds
	mid := (upp - low + 1) / 2

	// Base cases for the search
	if upp-low < 0 {
		return 0
	} else if li[from] >= target {
		return 0
	} else if li[upp] < target {
		return upp - low + 1
	}

	// Perform binary search to find the count of valid integers
	for upp-low > 1 {
		if li[mid] >= target {
			upp = mid
		} else {
			low = mid
		}
		// Update mid index after adjusting low and upp
		mid = (upp - low + 1) / 2
	}

	// Return the count of valid integers found
	return low - from + 1
}

