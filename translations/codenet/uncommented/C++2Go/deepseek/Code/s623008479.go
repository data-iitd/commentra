package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	sort.Ints(l)

	ans := 0
	for i := 0; i < k; i++ {
		ans += l[n - 1 - i]
	}
	fmt.Println(ans)
}

