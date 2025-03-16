
package main

import "fmt"

func root(x int) int {
	if par[x] == x {
		return x
	}
	return root(par[x])
}

func same(x, y int) bool {
	return root(x) == root(y)
}

func unite(z ...int) {
	x, y := root(z[0]), root(z[1])
	if x != y {
		if rank[x] < rank[y] {
			par[x] = y
			size[y] += size[x]
		} else {
			par[y] = x
			size[x] += size[y]
			if rank[x] == rank[y] {
				rank[x] += 1
			}
		}
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	par := make([]int, n)
	rank := make([]int, n)
	size := make([]int, n)
	for i := range par {
		par[i] = i
		rank[i] = 1
		size[i] = 1
	}
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	b := make([]int, n)
	for i, t := range a {
		b[t-1] = i
	}
	c := 0
	for k := n - 1; k >= 0; k-- {
		l, r := 1, 1
		if k > 0 && a[k-1] > a[k] {
			l += size[root(k-1)]
			unite(k-1, k)
		}
		if k+1 < n && a[k+1] > a[k] {
			r += size[root(k+1)]
			unite(k+1, k)
		}
		c += l * r * a[k]
	}
	fmt.Println(c)
}

