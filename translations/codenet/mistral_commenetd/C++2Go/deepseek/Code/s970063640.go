package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, a int
	fmt.Scan(&n)
	fmt.Scan(&a)

	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	sort.Ints(s)

	sum := 0
	for i := n - 1; i > n - a - 1; i-- {
		sum += s[i]
	}

	fmt.Println(sum)
}

