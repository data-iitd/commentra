package main

import (
	"fmt"
	"math"
)

type edge struct {
	to   int
	pre  int
	c    int
}

const N = 1e5 + 10

var (
	e    [N << 1]edge
	u    [N]int
	l    int
	n    int
	m    int
	vis  [N]bool
	ok   bool
	cnt  [3]int
	d    [N]int
	T    int
)

func ins(a, b, c int) {
	e[l] = edge{b, u[a], c}
	u[a] = l
	l++
}

func dfs(x, l int) {
	vis[x] = true
	cnt[l]++
	d[x] = l
	reg(i, x)
		if !vis[v] {
			dfs(v, (l+ec)%3)
		} else if (l+ec)%3 != d[v] {
			ok = false
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
	var ans float64
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
				ans += float64(s * s)
			} else {
				if cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0 {
					ans += float64(cnt[0]*cnt[1] + cnt[1]*cnt[2] + cnt[2]*cnt[0])
				} else {
					ans += float64(T / 2)
				}
			}
		}
	}
	fmt.Println(ans)
}
