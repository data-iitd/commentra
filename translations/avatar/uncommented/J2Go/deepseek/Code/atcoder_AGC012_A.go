package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	array := make([]int, 3*n)
	for i := 0; i < len(array); i++ {
		fmt.Scan(&array[i])
	}

	sort.Ints(array)
	head := len(array) - 2
	var res int64 = 0
	for i := 0; i < n; i++ {
		res += int64(array[head])
		head -= 2
	}
	fmt.Println(res)
}

