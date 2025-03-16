package main

import (
	"fmt"
	"sort"
)

const SIZE = (1e5 * 2) + 13

func main() {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	cnt := make([]int, SIZE)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		cnt[x]++
	}
	a := make([]int, 0)
	for i := 0; i < len(cnt); i++ {
		if cnt[i] > 0 {
			a = append(a, cnt[i])
		}
	}
	sort.Ints(a)
	var ans int
	m := len(a) - k
	for i := 0; i < m; i++ {
		ans += a[i]
	}
	fmt.Println(ans)
}

