
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// <START-OF-CODE>

// Task structure
type Task struct {
}

// NewTask returns a new instance of Task
func NewTask() *Task {
	return &Task{}
}

// Solve method
func (t *Task) Solve(input string) string {
	// Parse the input
	arr := strings.Split(input, " ")
	n, _ := strconv.Atoi(arr[0])
	arr = arr[1:]
	arrInt := make([]int, n)
	for i := 0; i < n; i++ {
		arrInt[i], _ = strconv.Atoi(arr[i])
	}

	// Sort the array
	sort.Ints(arrInt)

	// Initialize variables
	total := n * (n + 1) / 2
	l, r := 0, n-1
	var target int

	// Binary search
	for l < r {
		mid := l + (r-l)/2
		target = arrInt[mid]

		// Initialize variables
		cur, cnt := 0, 0
		bit := make([]int, 2*n+2)

		// Initialize the bitmap
		for x := n + 1; x < len(bit); x += x & -x {
			bit[x]++
		}

		// Process each element in the original array
		for i := 0; i < n; i++ {
			cur += arrInt[i] <= target
			for x := cur + n + 1; x < len(bit); x += x & -x {
				bit[x]++
			}
			for x := cur + n; x > 0; x -= x & -x {
				cnt += bit[x]
			}
		}

		if cnt >= total/2+1 {
			r = mid
		} else {
			l = mid + 1
		}
	}

	// Return the middle element as the answer
	return fmt.Sprintf("%d", arrInt[l])
}

// 