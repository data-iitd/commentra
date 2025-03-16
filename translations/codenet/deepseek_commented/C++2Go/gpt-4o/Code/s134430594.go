package main

import (
	"fmt"
	"math"
)

type Ban struct {
	l, r, val int64
}

type SparseTable struct {
	mn [][]int64
	pw []int64
}

func NewSparseTable(n int) *SparseTable {
	mn := make([][]int64, 20)
	for i := range mn {
		mn[i] = make([]int64, n)
	}
	pw := make([]int64, n)
	return &SparseTable{mn: mn, pw: pw}
}

func (st *SparseTable) Init(a []int64) {
	n := int64(len(a))
	for i := int64(0); i < n; i++ {
		st.mn[0][i] = a[i]
	}
	for i := 0; i+1 < 20; i++ {
		for j := int64(0); j+(1<<(i+1)) <= n; j++ {
			st.mn[i+1][j] = int64(math.Max(float64(st.mn[i][j]), float64(st.mn[i][j+(1<<i)])))
		}
	}
	st.pw[1] = 0
	for i := int64(2); i < n; i++ {
		st.pw[i] = st.pw[i/2] + 1
	}
}

func (st *SparseTable) Get(l, r int64) int64 {
	r++
	p := st.pw[r-l]
	return int64(math.Min(float64(st.mn[p][l]), float64(st.mn[p][r-(1<<p)])))
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
	bans := []Ban{}
	for i := int64(0); i < n; i++ {
		r := i
		for r+1 < n && a[r]+1 == a[r+1] {
			r++
		}
		ans += a[r]
		i = r
		bans = append(bans, Ban{l: r - a[r], r: r, val: r - a[r]})
	}

	st := NewSparseTable(int(n))
	st.Init(dl)
	for _, t := range bans {
		if st.Get(t.l, t.r) > t.val {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
