package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var elements []int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		elements = append(elements, num)
	}

	sort.Ints(elements)
	sum := 0
	for i := 0; i < k; i++ {
		sum += elements[i]
	}

	fmt.Println(sum)
}

