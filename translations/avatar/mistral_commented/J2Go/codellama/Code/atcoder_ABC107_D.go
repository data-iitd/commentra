
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Initialize scanner for reading input
	scan := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array
	var N int
	scan.Scan()
	fmt.Sscan(scan.Text(), &N)

	// Allocate memory for the array
	arr := make([]int, N)

	// Read the elements of the array
	for i := 0; i < N; i++ {
		scan.Scan()
		fmt.Sscan(scan.Text(), &arr[i]) // Read an element
	}

	// Create an instance of the Task class and call its solve method
	tsk := Task{}
	fmt.Println(tsk.Solve(arr)) // Print the result
}

type Task struct{}

// Method to solve the problem
func (tsk *Task) Solve(arr []int) int {
	n := len(arr) // Number of elements in the array

	// Create a copy of the array for sorting
	sorted := make([]int, n)
	copy(sorted, arr)
	sort.Ints(sorted) // Sort the copy in ascending order

	total := (n * (n + 1)) / 2 // Calculate the total sum of elements from 1 to n^2

	l, r := 0, n-1 // Initialize left and right pointers for binary search

	for l < r {
		mid := l + (r-l)/2 // Calculate the middle index
		target := sorted[mid] // The middle element is the target for this iteration

		cur := 0 // Initialize current sum
		cnt := 0 // Initialize count of elements less than or equal to target

		bit := make([]int, 2*n+2) // Bitmap array for fast counting

		// Initialize the bitmap array
		for x := n + 1; x < len(bit); x += x & -x {
			bit[x]++ // Increment the count for the current position
		}

		// Process each element in the original array
		for i := 0; i < n; i++ {
			cur += arr[i] <= target ? 1 : -1 // Increment the current sum if the element is less than or equal to target
			for x := cur + n + 1; x < len(bit); x += x & -x {
				bit[x]++ // Increment the count for the current position
			}
			for x := cur + n; x > 0; x -= x & -x {
				cnt += bit[x] // Add the count of elements with sum less than or equal to current sum
			}
		}

		if cnt >= total/2+1 { // If the count is greater than half the total sum
			r = mid // Narrow the search range to the left
		} else {
			l = mid + 1 // Narrow the search range to the right
		}
	}

	// Return the middle element as the answer
	return sorted[l]
}

// 