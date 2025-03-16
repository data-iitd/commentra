package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	sort.Ints(a)

	min := a[0]

	for _, value := range a {
		if value%min != 0 {
			fmt.Println(-1)
			return
		}
	}

	fmt.Println(min)
}

