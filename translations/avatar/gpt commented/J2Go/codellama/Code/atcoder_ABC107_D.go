package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Create a scanner object to read input from the standard input stream
	scan := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array
	var N int
	fmt.Scan(&N)

	// Initialize an array to hold the input integers
	arr := make([]int, N)

	// Populate the array with input integers
	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
	}

	// Create an instance of the Task class to perform the calculation
	tsk := Task{}

	// Solve the task and print the result
	fmt.Println(tsk.Solve(arr))
}

type Task struct{}

func (tsk Task) Solve(arr []int) int {
	// Get the length of the input array
	n := len(arr)

	// Create a sorted copy of the input array
	sorted := make([]int, n)
	copy(sorted, arr)
	sort.Ints(sorted)

	// Calculate the total number of pairs possible in the array
	total := int64(n * (n + 1) / 2)

	// Initialize pointers for binary search
	l, r := 0, n-1

	// Perform binary search to find the median-like value
	for l < r {
		// Calculate the midpoint of the current search range
		mid := l + (r-l)/2

		// Get the target value from the sorted array
		target := sorted[mid]

		// Initialize counters for the current state
		cur, cnt := 0, int64(0)

		// Create a Binary Indexed Tree (BIT) for counting
		bit := make([]int64, 2*n+2)

		// Initialize the BIT with base values
		for x := n + 1; x < len(bit); x += x & -x {
			bit[x]++
		}

		// Count the number of elements less than or equal to the target
		for i := 0; i < n; i++ {
			cur += arr[i] <= target ? 1 : -1

			// Update the BIT with the current count
			for x := cur + n + 1; x < len(bit); x += x & -x {
				bit[x]++
			}

			// Count the number of valid pairs using the BIT
			for x := cur + n; x > 0; x -= x & -x {
				cnt += bit[x]
			}
		}

		// Adjust the search range based on the count of pairs
		if cnt >= total/2+1 {
			r = mid // Move left if count is sufficient
		} else {
			l = mid + 1 // Move right if count is insufficient
		}
	}

	// Return the median-like value found
	return sorted[l]
}

// 