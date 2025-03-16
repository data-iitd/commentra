package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k, t int
	fmt.Scan(&n, &k)
	var vec []int
	for i := 0; i < n; i++ {
		fmt.Scan(&t)
		vec = append(vec, t)
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

