package main

import (
	"fmt"
	"sort"
)

var n, k, t int
var vec []int
var ans int = 1000000001

func main() {
	fmt.Scan(&n, &k)
	for i := 0; i < n; i++ {
		fmt.Scan(&t)
		vec = append(vec, t)
	}
	sort.Ints(vec)
	for i := 0; i+k-1 < n; i++ {
		diff := vec[i+k-1] - vec[i]
		if diff < ans {
			ans = diff
		}
	}
	fmt.Println(ans)
}

