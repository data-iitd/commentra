
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	const MOD = 100000007
	const N = 100000
	var n int
	var a [N]int
	var b [N]int
	var par [N]int
	var rank [N]int
	var size [N]int
	var c int
	var l, r int
	var k int
	var x, y int
	var t int
	var i int
	var s string
	var f *os.File
	var r *bufio.Reader
	var w *bufio.Writer

	f = os.Stdin
	r = bufio.NewReader(f)
	w = bufio.NewWriter(os.Stdout)

	fmt.Fscanf(r, "%d\n", &n)
	for i = 0; i < n; i++ {
		fmt.Fscanf(r, "%d ", &a[i])
		b[a[i]-1] = i
	}
	for i = 0; i < n; i++ {
		par[i] = i
		rank[i] = 1
		size[i] = 1
	}
	c = 0
	for k = n - 1; k >= 0; k-- {
		l = 1
		r = 1
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
	fmt.Fprintf(w, "%d\n", c)
	w.Flush()
}

func root(x int) int {
	if par[x] == x {
		return x
	}
	par[x] = root(par[x])
	return par[x]
}

func same(x, y int) bool {
	return root(x) == root(y)
}

func unite(x, y int) {
	x = root(x)
	y = root(y)
	if x!= y {
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

