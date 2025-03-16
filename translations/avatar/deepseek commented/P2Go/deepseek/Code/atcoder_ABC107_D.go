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
	uniqueA := append([]int(nil), a...)
	uniqueA = append(uniqueA, 0)
	sort.Ints(uniqueA)
	for i, x := range uniqueA {
		d[x] = i
	}
	for i := range a {
		a[i] = d[a[i]]
	}

	check := func(X int) bool {
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
		for i := range b {
			b[i] -= c
		}
		bit := &BIT{size: max(b) + 2, tree: make([]int, max(b) + 2 + 1)}
		ans := 0
		for _, x := range b {
			ans += bit.bitsum(x + 1)
			bit.bitadd(x, 1)
		}
		return ans >= m
	}

	t := []int{len(uniqueA) - 1, 0}
	for t[0] - t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(uniqueA[mid]) {
			t[0] = mid
		} else {
			t[1] = mid
		}
	}

	fmt.Fprintln(writer, uniqueA[t[1]])
