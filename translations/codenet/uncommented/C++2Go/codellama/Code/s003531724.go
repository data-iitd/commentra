package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	e := make([][]int, n+1)
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		e[a] = append(e[a], b)
		e[b] = append(e[b], a)
	}
	cnt := make([]int, 3)
	ok := true
	var dfs func(int, int)
	dfs = func(x, l int) {
		cnt[l]++
		for _, v := range e[x] {
			if v == x {
				continue
			}
			if cnt[(l+1)%3] == 0 {
				dfs(v, (l+1)%3)
			} else if (l+1)%3 != cnt[(l+1)%3]-1 {
				ok = false
			}
		}
	}
	ans := 0
	for i := 1; i <= n; i++ {
		if len(e[i]) == 0 {
			continue
		}
		for j := 0; j < 3; j++ {
			cnt[j] = 0
		}
		ok = true
		dfs(i, 0)
		s := cnt[0] + cnt[1] + cnt[2]
		if !ok {
			ans += s * s
		} else {
			if cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0 {
				ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
			} else {
				ans += len(e[i]) / 2
			}
		}
	}
	fmt.Println(ans)
}

