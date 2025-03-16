package main

import (
	"fmt"
	"sort"
)

const SIZE = (1e5 * 2) + 13

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	cnt := make([]int, SIZE)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		cnt[x]++
	}

	a := []int{}
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

// <END-OF-CODE>
