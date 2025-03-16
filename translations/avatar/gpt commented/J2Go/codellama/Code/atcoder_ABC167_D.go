
package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize scanner for input
	sc := make([]int, 1000001)

	// Constants for modulo and limits
	MOD := 1000000007
	MAX := math.MaxInt32
	LMAX := math.MaxInt64

	// Length for the array
	len := 1000001

	// Read the number of elements N and the long value K
	N := sc[0]
	K := sc[1]

	// Initialize the array A to store the input values
	A := make([]int, N)

	// Read N integers into the array A and adjust values to be zero-indexed
	for i := 0; i < N; i++ {
		A[i] = sc[i+2] - 1
	}

	// Set to track used indices and arrays to store index and position
	used := make([]bool, len)
	idx := make([]int, len)
	pos := make([]int, len)

	// Initialize variables for the cycle detection
	next := 0
	cur := 0

	// Detect the cycle in the array using the 'used' set
	for !used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	// Calculate the lengths of the cycle and the position of the next element
	a := (cur - idx[next])
	b := idx[next]

	// Calculate the answer based on the cycle length and K
	ans := (10000*a + K - b) % a + b

	// If b is greater than K, set ans to K
	if b > K {
		ans = int(K)
	}

	// Output the result, adjusting for 1-based indexing
	fmt.Println(pos[ans] + 1)
}

