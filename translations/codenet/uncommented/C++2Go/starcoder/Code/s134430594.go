package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanln(reader, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanln(reader, &a[i])
	}
	dl := make([]int, n)
	for i := 0; i < n; i++ {
		dl[i] = i - a[i]
	}
	ans := 0
	bans := make([]Ban, n)
	for i := 0; i < n; i++ {
		r := i
		for r + 1 < n && a[r] + 1 == a[r + 1] {
			r++
		}
		ans += a[r]
		i = r
		bans[i] = Ban{r - a[r], r, r - a[r]}
	}
	init(dl)
	for _, t := range bans {
		if get(t.l, t.r) > t.val {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(ans)
}

type Ban struct {
	l, r, val int
}

func init(a []int) {
	n := len(a)
	mn := make([][]int, 20)
	pw := make([]int, n)
	for i := 0; i < 20; i++ {
		mn[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		mn[0][i] = a[i]
	}
	for i := 0; i + 1 < 20; i++ {
		for j := 0; j + (1<<uint(i+1)) <= n; j++ {
			mn[i+1][j] = max(mn[i][j], mn[i][j+(1<<uint(i))])
		}
	}
	pw[1] = 0
	for i := 2; i < n; i++ {
		pw[i] = pw[i/2] + 1
	}
	Sp.mn = mn
	Sp.pw = pw
}

func get(l, r int) int {
	r++
	p := Sp.pw[r-l]
	return min(Sp.mn[p][l], Sp.mn[p][r-(1<<uint(p))])
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

