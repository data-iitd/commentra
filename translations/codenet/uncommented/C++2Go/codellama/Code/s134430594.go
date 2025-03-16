
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	dl := make([]int, n)
	for i := 0; i < n; i++ {
		dl[i] = i - a[i]
	}
	ans := 0
	bans := make([]Ban, 0)
	for i := 0; i < n; i++ {
		r := i
		for r+1 < n && a[r] + 1 == a[r+1] {
			r++
		}
		ans += a[r]
		i = r
		bans = append(bans, Ban{r - a[r], r, r - a[r]})
	}
	SpInit(dl)
	for _, t := range bans {
		if SpGet(t.l, t.r) > t.val {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(ans)
}

type Ban struct {
	l, r, val int
}

const (
	LIM = 20
	N   = 2e5 + 7
)

var (
	mn [LIM][N]int
	pw [N]int
)

func SpInit(a []int) {
	n := len(a)
	for i := 0; i < n; i++ {
		mn[0][i] = a[i]
	}
	for i := 0; i+1 < LIM; i++ {
		for j := 0; j+1+(1<<i) <= n; j++ {
			mn[i+1][j] = max(mn[i][j], mn[i][j+(1<<i)])
		}
	}
	pw[1] = 0
	for i := 2; i < N; i++ {
		pw[i] = pw[i/2] + 1
	}
}

func SpGet(l, r int) int {
	r++
	p := pw[r-l]
	return min(mn[p][l], mn[p][r-(1<<p)])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

