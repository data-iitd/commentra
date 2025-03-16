package main

import (
	"fmt"
)

const MOD = 1000000007
const MAX = int(^uint(0) >> 1) // Maximum integer value
const LMAX = int64(^uint64(0) >> 1) // Maximum long value
const lenArray = 1000001 // Length of the array

func main() {
	var N int
	var K int64
	fmt.Scan(&N, &K) // Reading the number of elements in the array and the long value K
	A := make([]int, N) // Creating an integer slice A of size N

	// Reading the elements of the array A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		A[i]-- // Subtracting 1 from the input to get the index of the previous element
	}

	used := make(map[int]bool) // Creating a map to store the indices that have already been processed
	idx := make([]int, N) // Creating a slice named idx to store the position of the current index in the circular array
	pos := make([]int, N) // Creating a slice named pos to store the position of the previous index in the circular array
	next, cur := 0, 0 // Initializing the variables next and cur

	// Finding the cycle starting point using BFS
	for !used[next] {
		used[next] = true // Marking the current index as used
		idx[next] = cur // Storing the current position in the idx slice
		pos[cur] = next // Storing the previous position in the pos slice
		next = A[next] // Moving to the next index
		cur++ // Incrementing the current position
	}

	a := int64(cur - idx[next]) // Calculating the length of the cycle
	b := int64(idx[next]) // Calculating the starting position of the cycle in the array
	ans := int((10000*a + K - b + MOD) % a + b) // Calculating the answer using the formula

	// Checking if the starting position of the cycle is greater than K, if yes then the answer is K
	if b > K {
		ans = int(K)
	}

	fmt.Println(pos[ans] + 1) // Printing the position of the answer in the array
}

// <END-OF-CODE>
