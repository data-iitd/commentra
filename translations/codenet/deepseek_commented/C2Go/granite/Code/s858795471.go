
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func search(A []int, n int, key int) int {
	i := 0
	// Add the key to the end of the array to handle the case where the key is not found
	A[n] = key
	// Loop until the key is found in the array
	for A[i]!= key {
		i++
	}
	// Return 1 if the key is found, otherwise return 0
	return i!= n
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialCapacity = 10000 + 1
	var n int
	fmt.Scan(&n)
	A := make([]int, initialCapacity)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	var q int
	fmt.Scan(&q)
	sum := 0
	for i := 0; i < q; i++ {
		fmt.Scan(&n)
		// Perform the search operation for the current query element
		if search(A, n, q) {
			sum++
		}
	}
	fmt.Println(sum)
}

