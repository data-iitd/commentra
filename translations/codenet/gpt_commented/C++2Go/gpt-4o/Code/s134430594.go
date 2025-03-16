package main

import (
	"fmt"
)

type Ban struct {
	l, r, val int64
}

const LIM = 20
const N = 200007

var mn [LIM][N]int64
var pw [N]int64

func initSparseTable(a []int64) {
	n := int64(len(a))
	for i := int64(0); i < n; i++ {
		mn[0][i] = a[i]
	}
	for i := int64(0); i+1 < LIM; i++ {
		for j := int64(0); j+(1<<(i+1)) <= n; j++ {
			mn[i+1][j] = max(mn[i][j], mn[i][j+(1<<i)])
		}
	}
	pw[1] = 0
	for i := int64(2); i < N; i++ {
		pw[i] = pw[i/2] + 1
	}
}

func get(l, r int64) int64 {
	r++
	p := pw[r-l]
	return min(mn[p][l], mn[p][r-(1<<p)])
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n int64
	fmt.Scan(&n)
	a := make([]int64, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	dl := make([]int64, n)
	for i := int64(0); i < n; i++ {
		if a[i] > i {
			fmt.Println(-1)
			return
		}
		dl[i] = i - a[i]
	}

	ans := int64(0)
	var bans []Ban
	for i := int64(0); i < n; i++ {
		r := i
		for r+1 < n && a[r]+1 == a[r+1] {
			r++
		}
		ans += a[r]
		i = r
		bans = append(bans, Ban{l: r - a[r], r: r, val: r - a[r]})
	}

	initSparseTable(dl)
	for _, t := range bans {
		if get(t.l, t.r) > t.val {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
