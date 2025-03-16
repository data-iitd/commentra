package main

import (
	"fmt"
)

// Linear Search Function
// Purpose: This function performs a linear search to find the key in the array S.
// Parameters:
//   - S: The array to be searched.
//   - n: The size of the array S.
//   - key: The value to be searched for.
// Return Value: Returns 1 if the key is not found, otherwise returns 0.
func linearsearch(S []int, n int, key int) int {
	i := 0
	for S[i] != key {
		i++
		if i >= n {
			return 1
		}
	}
	return 0
}

// Main Function
// Purpose: This function reads two arrays S and T, and counts the number of elements in T that are present in S using the linearsearch function.
// Variables:
//   - i, j: Loop counters.
//   - n, q: Sizes of arrays S and T.
//   - S: The first array to be read.
//   - T: The second array to be read.
//   - count: Counter for the number of elements found.
//   - key: The current element being searched for in S.
func main() {
	var i, j, n, q int
	var S, T []int
	var count int
	var key int

	fmt.Scan(&n)
	S = make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Scan(&S[i])
	}

	fmt.Scan(&q)
	T = make([]int, q)
	for j = 0; j < q; j++ {
		fmt.Scan(&T[j])
	}

	for j = 0; j < q; j++ {
		key = T[j]
		if linearsearch(S, n, key) == 0 {
			count++
		}
	}

	fmt.Println(count)
}

