package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	vec := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&vec[i])
	}

	sort.Ints(vec)

	ans := 1000000001
	for i := 0; i+k-1 < n; i++ {
		diff := vec[i+k-1] - vec[i]
		if diff < ans {
			ans = diff
		}
	}

	fmt.Println(ans)
}

