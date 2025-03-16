package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type BIT struct {
	size int
	tree []int
	depth int
}

func (b *BIT) _bitsum(i int) int {
	ret := 0
	for i > 0 {
		ret += b.tree[i]
		i ^= i & -i
	}
	return ret
}

func (b *BIT) bitsum(l, r int) int {
	if r == -1 {
		return b._bitsum(l)
	}
	return b._bitsum(r) - b._bitsum(l)
}

func (b *BIT) bitadd(i, x int) {
	i++
	for i <= b.size {
		b.tree[i] += x
		i += i & -i
	}
}

func check(X int, n int, m int, a []int, d map[int]int) bool {
	b := make([]int, n+1)
	for i := 0; i < n; i++ {
		if a[i] >= X {
			b[i+1] = 1
		} else {
			b[i+1] = -1
		}
	}
	for i := 1; i <= n; i++ {
		b[i] += b[i-1]
	}
	c := b[0]
	for i := 0; i <= n; i++ {
		b[i] -= c
	}
	bit := BIT{size: len(b), tree: make([]int, len(b)+1)}
	ans := 0
	for _, x := range b {
		ans += bit.bitsum(x+1, -1)
		bit.bitadd(x, 1)
	}
	return ans >= m
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	m := n * (n + 1) / 4
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	d := make(map[int]int)
	_a := append(a, 0)
	_a = append(_a, a...)
	sort.Ints(_a)
	_a = append(unique(_a), 0)
	for i, x := range _a {
		d[x] = i
	}
	for i := 0; i < n; i++ {
		a[i] = d[a[i]]
	}

	t := []int{len(_a), 0}
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(mid, n, m, a, d) {
			t[1] = mid
		} else {
			t[0] = mid
		}
	}
	fmt.Fprintln(writer, _a[t[1]])
}

func unique(a []int) []int {
	occurred := map[int]bool{}
	result := []int{}
	for i := range a {
		if occurred[a[i]] != true {
			occurred[a[i]] = true
			result = append(result, a[i])
		}
	}
	return result
}
