package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)

	// Read the elements of the array
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Sort the array in ascending order
	sort.Ints(l)

	cnt := 0

	// Count the number of valid triangles that can be formed
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			for k := j + 1; k < n; k++ {
				if l[i]+l[j] > l[k] {
					cnt++
				} else {
					break
				}
			}
		}
	}

	// Print the count of valid triangles
	fmt.Println(cnt)
}

// <END-OF-CODE>
