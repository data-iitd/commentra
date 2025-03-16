package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize scanner for input
	sc := bufio.NewScanner(os.Stdin)
	
	// Constants for modulo and limits
	const MOD = 1000000007
	const MAX = int(^uint(0) >> 1)
	const LMAX = int64(^uint64(0) >> 1)
	
	// Length for the array
	const len = 1000001
	
	// Read the number of elements N and the long value K
	var N int
	var K int64
	fmt.Scan(&N, &K)
	
	// Initialize the array A to store the input values
	A := make([]int, N)
	
	// Read N integers into the array A and adjust values to be zero-indexed
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		A[i]--
	}
	
	// Set to track used indices and arrays to store index and position
	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)
	
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
	a := int64(cur - idx[next])
	b := int64(idx[next])
	
	// Calculate the answer based on the cycle length and K
	ans := (int64(10000) * a + K - b) % a + b
	
	// If b is greater than K, set ans to K
	if b > K {
		ans = K
	}
	
	// Output the result, adjusting for 1-based indexing
	fmt.Println(pos[ans] + 1)
}
