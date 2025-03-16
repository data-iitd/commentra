package main

import (
	"fmt"
)

const N = 1e5 + 10

type Edge struct {
	to, pre, c int
}

var (
	e      [N * 2]Edge
	u      [N]int
	l      int
	n, m   int
	vis    [N]bool
	ok     bool
	cnt    [3]int64
	d      [N]int
	T      int
)

func ins(a, b, c int) {
	l++
	e[l] = Edge{b, u[a], c}
	u[a] = l
}

func dfs(x, l int) {
	vis[x] = true
	cnt[l]++
	d[x] = l

	for i := u[x]; i > 0; i = e[i].pre {
		T++
		v := e[i].to
		ec := e[i].c
		if !vis[v] {
			dfs(v, (l+ec)%3)
		} else if (l+ec)%3 != d[v] {
			ok = false
		}
	}
}

func main() {
	fmt.Scan(&n, &m)

	for i := 1; i <= m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		ins(a, b, 1)
		ins(b, a, 2)
	}

	var ans int64 = 0

	for i := 1; i <= n; i++ {
		if !vis[i] {
			T = 0
			for j := 0; j < 3; j++ {
				cnt[j] = 0
			}
			ok = true
			dfs(i, 0)

			s := cnt[0] + cnt[1] + cnt[2]

			if !ok {
				ans += s * s
			} else {
				if cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0 {
					ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
				} else {
					ans += int64(T) / 2
				}
			}
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
