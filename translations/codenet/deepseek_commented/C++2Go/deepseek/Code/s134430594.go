package main

import (
	"fmt"
	"math"
)

// Structure to store the left, right, and value of a ban
type Ban struct {
	l   int
	r   int
	val int
}

// Namespace for sparse table operations
const (
	LIM = 20
	N   = 2e5 + 7
)

var (
	mn [LIM][N]int
	pw [N]int
)

// Initialize the sparse table with the given array
func initSparseTable(a []int) {
	n := len(a)
	for i := 0; i < n; i++ {
		mn[0][i] = a[i]
	}
	for i := 0; i+1 < LIM; i++ {
		for j := 0; j+(1<<(i+1)) <= n; j++ {
			mn[i+1][j] = max(mn[i][j], mn[i][j+(1<<i)])
		}
	}
	pw[1] = 0
	for i := 2; i < N; i++ {
		pw[i] = pw[i/2] + 1
	}
}

// Query the sparse table for the minimum value in the range [l, r)
func getSparseTable(l, r int) int {
	r++
	p := pw[r-l]
	return max(mn[p][l], mn[p][r-(1<<p)])
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	dl := make([]int, n)
	for i := 0; i < n; i++ {
		if a[i] > i {
			fmt.Println(-1)
			return
		}
		dl[i] = i - a[i]
	}
	ans := 0
	var bans []Ban
	for i := 0; i < n; i++ {
		r := i
		for r+1 < n && a[r]+1 == a[r+1] {
			r++
		}
		ans += a[r]
		i = r
		bans = append(bans, Ban{r - a[r], r, r - a[r]})
	}
	initSparseTable(dl)
	for _, t := range bans {
		if getSparseTable(t.l, t.r) > t.val {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

