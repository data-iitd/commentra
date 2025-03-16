package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	cnt := make([]int, SIZE)
	a := make([]int, 0)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		cnt[x]++
	}
	for i := 0; i < len(cnt); i++ {
		if cnt[i] > 0 {
			a = append(a, cnt[i])
		}
	}
	ans := 0
	sort.Ints(a)
	m := len(a) - k
	for i := 0; i < m; i++ {
		ans += a[i]
	}
	fmt.Println(ans)
}

