package main

import (
	"fmt"
	"sort"
)

// Define a function to compare two integers
func compare(a, b int) int {
	return b - a
}

func main() {
	var array [10]int
	for i := 0; i < 10; i++ {
		fmt.Scan(&array[i])
	}
	sort.Slice(array, func(i, j int) bool {
		return compare(array[i], array[j]) > 0
	})
	for i := 0; i < 3; i++ {
		fmt.Println(array[i])
	}
}

