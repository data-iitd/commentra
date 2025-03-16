package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)

	for n := 0; n < N; n++ {
		fmt.Scan(&A[n])
	}

	sort.Ints(A)
	min := A[0]
	max := A[N-1]
	mins, maxs := 0, 0

	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}

	if min == max {
		fmt.Println((max - min), (mins*(mins-1))/2)
	} else {
		fmt.Println((max - min), (mins * maxs))
	}
}

// <END-OF-CODE>
