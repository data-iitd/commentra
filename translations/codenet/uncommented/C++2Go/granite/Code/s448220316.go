
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n, m, l, r, vi, fa, v int
	fmt.Fscanf(r, "%d%d\n", &n, &m)
	fa = n
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	for i := 1; i <= m; i++ {
		fmt.Fscanf(r, "%d%d%d\n", &l, &r, &vi)
		li, ri := get(l), get(r)
		if li!= ri {
			v[ri] = vi - v[r] + v[l]
			fa[ri] = li
		} else {
			if v[r]-v[l]!= vi {
				fmt.Fprintln(w, "No")
				w.Flush()
				return
			}
		}
	}
	fmt.Fprintln(w, "Yes")
	w.Flush()
}

func get(x int) int {
	if x == fa[x] {
		return x
	}
	f := get(fa[x])
	v[x] += v[fa[x]]
	return fa[x] = f
}

