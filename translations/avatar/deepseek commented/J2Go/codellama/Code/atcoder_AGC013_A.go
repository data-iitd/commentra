
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var N int
	var A []int
	var count int
	var i int
	var j int
	var temp int

	// Step 1: Read the input value N
	N, _ = strconv.Atoi(os.Args[1])

	// Step 2: Read the elements of the array A
	A = make([]int, N)
	for i = 0; i < N; i++ {
		A[i], _ = strconv.Atoi(os.Args[i+2])
	}

	// Step 3: Initialize a counter 'count' to zero
	count = 0

	// Step 4: Sort the array A
	for i = 0; i < N-1; i++ {
		for j = i + 1; j < N; j++ {
			if A[i] > A[j] {
				temp = A[i]
				A[i] = A[j]
				A[j] = temp
			}
		}
	}

	// Step 5: Check if the current index i is the last index
	for i = 0; i < N; i++ {
		if i == N-1 {
			count++
		} else if A[i] == A[i+1] {
			// Step 6: If the current element is equal to the next element
		} else if A[i] < A[i+1] {
			// Step 7: Increment the counter 'count' after each segment
			count++
		} else {
			// Step 8: Increment the counter 'count' after each segment
			count++
		}
	}

	// Step 9: Print the value of the counter 'count'
	fmt.Println(count)
}

