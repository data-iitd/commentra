
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Linear Search Function
// Purpose: This function performs a linear search to find the key in the array S.
// Parameters:
//   - S[]: The array to be searched.
//   - n: The size of the array S.
//   - key: The value to be searched for.
// Return Value: Returns 1 if the key is not found, otherwise returns 0.
func linearsearch(S []int, n int, key int) int {
	var i int
	var count int
	for i = 0; i < n; i++ {
		if S[i] == key {
			return 0
		}
	}
	count = 1
	return count
}

// Main Function
// Purpose: This function reads two arrays S and T, and counts the number of elements in T that are present in S using the linearsearch function.
// Variables:
//   - i, j: Loop counters.
//   - n, q: Sizes of arrays S and T.
//   - S[]: The first array to be read.
//   - T[]: The second array to be read.
//   - count: Counter for the number of elements found.
//   - key: The current element being searched for in S.
func main() {
	var i, j, n, q int
	var S []int
	var T []int
	var count int
	var key int

	reader := bufio.NewReader(os.Stdin)

	fmt.Fscanf(reader, "%d\n", &n)
	S = make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &S[i])
	}

	fmt.Fscanf(reader, "%d\n", &q)
	T = make([]int, q)
	for j = 0; j < q; j++ {
		fmt.Fscanf(reader, "%d\n", &T[j])
	}

	for j = 0; j < q; j++ {
		key, _ = strconv.Atoi(T[j])
		if linearsearch(S, n, key) == 0 {
			count++
		}
	}

	fmt.Println(count)
}
