package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	X := make([]int, N)
	Y := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&X[i])
		Y[i] = X[i]
	}
	sort.Ints(Y)
	y := Y[N/2]
	for i := 0; i < N; i++ {
		if X[i] < y {
			fmt.Println(y)
		} else {
			fmt.Println(y - 1)
		}
	}
}

