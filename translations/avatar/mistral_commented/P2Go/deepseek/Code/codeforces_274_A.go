package main

import (
	"fmt"
	"sort"
)

func main() {
	var num, k int
	fmt.Scan(&num, &k)

	var arr []int
	for i := 0; i < num; i++ {
		var x int
		fmt.Scan(&x)
		arr = append(arr, x)
	}

	sort.Ints(arr)

	different := make(map[int]bool)
	temp := 0

	for _, x := range arr {
		if x%k != 0 || !different[x/k] {
			different[x] = true
		}
		if len(different) > temp {
			temp = len(different)
		}
	}

	fmt.Println(temp)
}

