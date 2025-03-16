package main

import (
	"fmt"
	"sort"
)

func compare(a, b int) int {
	return b - a
}

func main() {
	array := make([]int, 10)
	for i := 0; i < 10; i++ {
		fmt.Scan(&array[i])
	}
	sort.Slice(array, func(i, j int) bool {
		return compare(array[i], array[j]) < 0
	})
	for i := 0; i < 3; i++ {
		fmt.Println(array[i])
	}
}

