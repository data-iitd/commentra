package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scanf("%d\n", &N)
	X := make([]int, N)
	Y := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &X[i])
		Y[i] = X[i]
	}
	sort.Ints(Y)
	y := Y[N/2]
	for i := 0; i < N; i++ {
		if X[i] < y {
			fmt.Printf("%d\n", y)
		} else {
			fmt.Printf("%d\n", y-1)
		}
	}
}

