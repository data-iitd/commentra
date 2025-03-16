
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements N
	N, _ := strconv.Atoi(read())

	// Allocate an array mem to store the positions of elements
	// The size of the array is N + 1 to accommodate 1-based indexing
	mem := make([]int, N+1)

	// Read the elements and store their positions in the array mem
	// The position is stored at the index corresponding to the element value
	for i := 1; i <= N; i++ {
		P, _ := strconv.Atoi(read())
		mem[P] = i
	}

	// Initialize variables to keep track of the longest increasing subsequence
	maxcnt := 1
	cnt := 1

	// Iterate through the array to find the longest increasing subsequence
	for i := 1; i < N; i++ {
		// Check if the current position is less than the next position
		if mem[i] < mem[i+1] {
			// Increment the count of the increasing subsequence
			cnt++
		} else {
			// Update the maximum count if the current count is greater
			if cnt > maxcnt {
				maxcnt = cnt
			}
			// Reset the count for the next subsequence
			cnt = 1
		}
		// Update the maximum count if the end of the array is reached
		if i == N-1 {
			if cnt > maxcnt {
				maxcnt = cnt
			}
		}
	}

	// Uncommented part of the code
//	cnt = 1
//	for i := N; i > 1; i-- {
//		if mem[i] > mem[i-1] {
//			cnt++
//		}
//	}

	// Output the result, which is the number of elements to remove
	// to make the sequence strictly decreasing
	fmt.Println(N - maxcnt)
}

func read() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

