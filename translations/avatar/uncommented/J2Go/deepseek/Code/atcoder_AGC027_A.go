package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	var x int64
	fmt.Scan(&N, &x)
	sweet := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&sweet[i])
	}
	sort.Slice(sweet, func(i, j int) bool {
		return sweet[i] < sweet[j]
	})
	num := 0
	for i := 0; i < N; i++ {
		if x-sweet[num] >= 0 {
			x = x - sweet[num]
			num++
		} else {
			break
		}
	}
	if num == N && x > 0 {
		num--
	}
	fmt.Println(num)
}

