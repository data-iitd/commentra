package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	cnt := make([]int, 1e5*2+13)
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

	sort.Ints(a)

	ans := 0
	m := len(a) - k
	for i := 0; i < m; i++ {
		ans += a[i]
	}

	fmt.Println(ans)
}

