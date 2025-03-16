package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	sort.Ints(A)

	min := A[0]
	max := A[N-1]

	var mins, maxs int64
	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}

	if min == max {
		fmt.Println(0, mins*(mins-1)/2)
	} else {
		fmt.Println(max-min, mins*maxs)
	}
}

