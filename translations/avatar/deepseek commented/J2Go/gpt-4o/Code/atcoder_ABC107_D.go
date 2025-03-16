package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	var N int
	fmt.Sscanf(scanner.Text(), "%d", &N) // Read the size of the array
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i]) // Read the array elements
	}

	tsk := Task{}
	fmt.Println(tsk.solve(arr)) // Print the result of the solve method
}

type Task struct{}

func (t Task) solve(arr []int) int {
	n := len(arr)
	sorted := make([]int, n)
	copy(sorted, arr) // Create a copy of the array
	sort.Ints(sorted) // Sort the array

	total := int64(n * (n + 1) / 2) // Calculate the total number of elements
	l, r := 0, n-1

	// Implement binary search to find the median
	for l < r {
		mid := l + (r-l)/2
		target := sorted[mid]
		cur := 0
		cnt := int64(0)
		bit := make([]int64, 2*n+2)

		for x := n + 1; x < len(bit); x += x & -x {
			bit[x]++
		} // Initialize the binary indexed tree

		for i := 0; i < n; i++ {
			if arr[i] <= target {
				cur++
			} else {
				cur--
			}
			for x := cur + n + 1; x < len(bit); x += x & -x {
				bit[x]++ // Update the binary indexed tree
			}
			for x := cur + n; x > 0; x -= x & -x {
				cnt += bit[x] // Calculate the count of elements less than or equal to the target
			}
		}

		if cnt >= total/2+1 {
			r = mid // Adjust the search range if the count is sufficient
		} else {
			l = mid + 1
		}
	}

	return sorted[l] // Return the median value
}

// <END-OF-CODE>
