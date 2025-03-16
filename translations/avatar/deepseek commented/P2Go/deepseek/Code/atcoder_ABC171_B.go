package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var numbers []int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		numbers = append(numbers, num)
	}

	sort.Ints(numbers)
	sum := 0
	for i := 0; i < k; i++ {
		sum += numbers[i]
	}

	fmt.Println(sum)
}

