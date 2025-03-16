package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Sort the array
	sort.Ints(l)

	cnt := 0

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

	fmt.Println(cnt)
}

// <END-OF-CODE>
