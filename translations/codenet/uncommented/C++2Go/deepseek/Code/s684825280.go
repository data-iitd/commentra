package main

import (
	"fmt"
	"sort"
)

const SIZE = (1e5 * 2) + 13

var a []int
var cnt [SIZE]int

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		cnt[x]++
	}
	for i := 0; i < SIZE; i++ {
		if cnt[i] > 0 {
			a = append(a, cnt[i])
		}
	}
	sort.Ints(a)
	m := len(a) - k
	var ans int
	for i := 0; i < m; i++ {
		ans += a[i]
	}
	fmt.Println(ans)
}

