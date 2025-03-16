package main

import (
	"fmt"
	"sort"
)

func main() {
	var a, b []*int
	var i, N int
	var frontHalf, backHalf int

	fmt.Scan(&N)

	a = make([]*int, N)
	b = make([]*int, N)

	for i = 0; i < N; i++ {
		a[i] = new(int)
		fmt.Scan(a[i])
		b[i] = new(int)
		*b[i] = *a[i]
	}

	sort.Slice(b, func(i, j int) bool {
		return *b[i] < *b[j]
	})

	frontHalf = *b[N/2-1]
	backHalf = *b[N/2]

	for i = 0; i < N; i++ {
		if *a[i] < backHalf {
			fmt.Println(backHalf)
		} else {
			fmt.Println(frontHalf)
		}
	}

	for i = 0; i < N; i++ {
		delete(a, i)
		delete(b, i)
	}
}

