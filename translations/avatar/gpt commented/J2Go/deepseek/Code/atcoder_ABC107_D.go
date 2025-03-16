package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the standard input stream
	scanner := bufio.NewScanner(bufio.NewReader(os.Stdin))
	
	// Read the number of elements in the array
	scanner.Scan()
	N := 0
	fmt.Sscan(scanner.Text(), &N)
	
	// Initialize an array to hold the input integers
	arr := make([]int, N)
	
	// Populate the array with input integers
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &arr[i])
	}
	
	// Create an instance of the Task struct to perform the calculation
	tsk := Task{}
	
	// Solve the task and print the result
	fmt.Println(tsk.solve(arr))
}

type Task struct {}

func (t Task) solve(arr []int) int {
	// Get the length of the input array
	n := len(arr)
	
	// Create a sorted copy of the input array
	sorted := make([]int, n)
	copy(sorted, arr)
	sort.Ints(sorted)
	
	// Calculate the total number of pairs possible in the array
	total := int64(n) * int64(n + 1) / 2
	
	// Initialize pointers for binary search
	l, r := 0, n - 1
	
	// Perform binary search to find the median-like value
	for l < r {
		// Calculate the midpoint of the current search range
		mid := l + (r - l) / 2
		
		// Get the target value from the sorted array
		target := sorted[mid]
		
		// Initialize counters for the current state
		cur := 0
		var cnt int64 = 0
		
		// Create a Binary Indexed Tree (BIT) for counting
		bit := make([]int64, 2 * n + 2)
		
		// Initialize the BIT with base values
		for x := n + 1; x <= 2 * n + 1; x += x & -x {
			bit[x]++
		}
		
		// Count the number of elements less than or equal to the target
		for i := 0; i < n; i++ {
			if arr[i] <= target {
				cur++
			} else {
				cur--
			}
			
			// Update the BIT with the current count
			for x := cur + n + 1; x <= 2 * n + 1; x += x & -x {
				bit[x]++
			}
			
			// Count the number of valid pairs using the BIT
			for x := cur + n; x > 0; x -= x & -x {
				cnt += bit[x]
			}
		}
		
		// Adjust the search range based on the count of pairs
		if cnt >= total / 2 + 1 {
			r = mid // Move left if count is sufficient
		} else {
			l = mid + 1 // Move right if count is insufficient
		}
	}
	
	// Return the median-like value found
	return sorted[l]
}
