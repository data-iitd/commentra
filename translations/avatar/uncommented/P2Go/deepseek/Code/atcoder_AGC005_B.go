package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	par   []int
	rank  []int
	size  []int
)

func root(x int) int {
	for par[x] != x {
		x = par[x]
	}
	return x
}

func same(x, y int) bool {
	return root(x) == root(y)
}

func unite(x, y int) {
	x = root(x)
	y = root(y)
	if x != y {
		if rank[x] < rank[y] {
			par[x] = y
			size[y] += size[x]
		} else {
			par[y] = x
			size[x] += size[y]
			if rank[x] == rank[y] {
				rank[x]++
			}
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n int
	scanner.Scan()
	n = atoi(scanner.Text())

	var a []int
	for i := 0; i < n; i++ {
		scanner.Scan()
		a = append(a, atoi(scanner.Text()))
	}

	par = make([]int, n)
	rank = make([]int, n)
	size = make([]int, n)
	for i := 0; i < n; i++ {
		par[i] = i
		size[i] = 1
	}

	b := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		t := atoi(scanner.Text()) - 1
		b[t] = i
	}

	c := 0
	for k := n - 1; k >= 0; k-- {
		l, r := 1, 1
		if b[k] > 0 && a[b[k]-1] > a[b[k]] {
			l += size[root(b[k]-1)]
			unite(b[k]-1, b[k])
		}
		if b[k] < n-1 && a[b[k]+1] > a[b[k]] {
			r += size[root(b[k]+1)]
			unite(b[k]+1, b[k])
		}
		c += l * r * a[b[k]]
	}

	fmt.Println(c)
}

func atoi(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

