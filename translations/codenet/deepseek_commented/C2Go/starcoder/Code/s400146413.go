<<<<<<< HEAD

import "fmt"
=======
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)
>>>>>>> 98c87cb78a (data updated)

// LinearSearch Function
// Purpose: This function performs a linear search to find the key in the array S.
// Parameters:
//   - S[]: The array to be searched.
//   - n: The size of the array S.
//   - key: The value to be searched for.
// Return Value: Returns 1 if the key is not found, otherwise returns 0.
func LinearSearch(S []int, n int, key int) int {
<<<<<<< HEAD
	var i int = 0
	var count int = 0
	for i = 0; i < n; i++ {
		if S[i] == key {
			count = 0
			return count
		}
	}
	count = 1
	return count
=======
	for i := 0; i < n; i++ {
		if S[i] == key {
			return 0
		}
	}
	return 1
>>>>>>> 98c87cb78a (data updated)
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
<<<<<<< HEAD
	var i, j, n, q int
	var S [10000]int
	var T [10000]int
	var count, key int
=======
	var i, j, n, q, count, key int
	var S, T []int
>>>>>>> 98c87cb78a (data updated)

	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &S[i])
	}

	fmt.Scanf("%d", &q)
	for j = 0; j < q; j++ {
		fmt.Scanf("%d", &T[j])
	}

	for j = 0; j < q; j++ {
		key = T[j]
		if LinearSearch(S, n, key) == 0 {
			count++
		}
	}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
	fmt.Printf("%d\n", count)
}

