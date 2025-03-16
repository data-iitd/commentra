package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	a := make([]int, N)
	b := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
		b[i] = a[i]
	}

	sort.Ints(b)

	var frontHalf, backHalf int
	if N%2 == 0 {
		frontHalf = b[N/2-1]
		backHalf = b[N/2]
	} else {
		frontHalf = b[N/2]
		backHalf = b[N/2]
	}

	for i := 0; i < N; i++ {
		if a[i] < backHalf {
			fmt.Println(backHalf)
		} else {
			fmt.Println(frontHalf)
		}
	}
}

// <END-OF-CODE>
