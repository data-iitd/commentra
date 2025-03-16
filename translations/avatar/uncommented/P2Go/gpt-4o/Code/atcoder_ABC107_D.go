package main

import (
	"fmt"
	"sort"
)

type BIT struct {
	size int
	tree []int
}

func NewBIT(N int) *BIT {
	return &BIT{
		size: N,
		tree: make([]int, N+1),
	}
}

func (bit *BIT) bitsum(i int) int {
	ret := 0
	for i > 0 {
		ret += bit.tree[i]
		i ^= i & -i
	}
	return ret
}

func (bit *BIT) Bitsum(l, r int) int {
	if r == -1 {
		return bit.bitsum(l)
	}
	return bit.bitsum(r) - bit.bitsum(l)
}

func (bit *BIT) Bitadd(i, x int) {
	i++
	for i <= bit.size {
		bit.tree[i] += x
		i += i & -i
	}
}

func check(X int, n int, a []int) bool {
	b := make([]int, n+1)
	b[0] = 0
	for i := 0; i < n; i++ {
		if a[i] >= X {
			b[i+1] = 1
		} else {
			b[i+1] = -1
		}
		b[i+1] += b[i]
	}
	c := b[0]
	for _, val := range b {
		if val < c {
			c = val
		}
	}
	for i := range b {
		b[i] -= c
	}
	bit := NewBIT(max(b...) + 2)
	ans := 0
	for _, x := range b {
		ans += bit.Bitsum(x+1, -1)
		bit.Bitadd(x, 1)
	}
	return ans >= (n*(n+1))/4
}

func max(arr ...int) int {
	m := arr[0]
	for _, v := range arr {
		if v > m {
			m = v
		}
	}
	return m
}

func main() {
	var n int
	fmt.Scan(&n)
	m := n * (n + 1) / 4
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	d := make(map[int]int)
	_a := make([]int, 0)
	_a = append(_a, 0)
	_a = append(_a, a...)
	sort.Ints(_a)
	for i, x := range _a {
		d[x] = i
	}
	for i := range a {
		a[i] = d[a[i]]
	}
	t := []int{len(_a), 0}
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(mid, n, a) {
			t[0] = mid
		} else {
			t[1] = mid
		}
	}
	fmt.Println(_a[t[1]])
}

// <END-OF-CODE>
