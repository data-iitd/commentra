package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(solve())
}

func solve() int {
	var N int
	fmt.Scan(&N)
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
	}
	sum := 0
	var q []int
	for i := 0; i < len(arr); i++ {
		q = append(q, arr[i])
		sort.Ints(q)
		if arr[i] <= q[0] {
			sum++
		}
	}
	return sum
}

