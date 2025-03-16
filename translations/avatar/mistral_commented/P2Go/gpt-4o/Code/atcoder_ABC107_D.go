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
		i &= i - 1 // Bitwise AND with the rightmost set bit
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
	i++ // Index i is 1-based in the tree
	for i <= bit.size {
		bit.tree[i] += x
		i += i & -i // Bitwise right propagation
	}
}

func check(X int, a []int, n int) bool {
	b := make([]int, n+1)
	b[0] = 0
	for i := 0; i < n; i++ {
		if a[i] >= X {
			b[i+1] = b[i] + 1
		} else {
			b[i+1] = b[i] - 1
		}
	}
	c := b[0]
	for i := 1; i <= n; i++ {
		if b[i] < c {
			c = b[i]
		}
	}
	for i := 0; i <= n; i++ {
		b[i] -= c
	}
	bit := NewBIT(max(b...) + 2) // Initialize BIT tree with the maximum value in b + 2
	ans := 0
	for _, x := range b {
		ans += bit.Bitsum(x+1, -1) // Calculate the sum of bits from index x+1 to the end
		bit.Bitadd(x, 1)           // Add 1 to the index x in the tree
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
	_a = unique(_a)

	for i, x := range _a {
		d[x] = i
	}

	for i := 0; i < n; i++ {
		a[i] = d[a[i]]
	}

	t := []int{len(_a), 0}
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(mid, a, n) {
			t[1] = mid
		} else {
			t[0] = mid
		}
	}

	fmt.Println(_a[t[1]])
}

func unique(ints []int) []int {
	uniqueMap := make(map[int]struct{})
	uniqueSlice := []int{}

	for _, v := range ints {
		if _, ok := uniqueMap[v]; !ok {
			uniqueMap[v] = struct{}{}
			uniqueSlice = append(uniqueSlice, v)
		}
	}
	return uniqueSlice
}

// <END-OF-CODE>
