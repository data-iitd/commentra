package main

import (
	"fmt"
)

var (
	n, m, l, r, vi int
	fa             [100005]int
	v              [200005]int
)

func read() int {
	var x int
	fmt.Scan(&x)
	return x
}

func write(x int) {
	if x < 0 {
		x = -x
		fmt.Print("-")
	}
	if x > 9 {
		write(x / 10)
	}
	fmt.Print(x % 10)
}

func writeln(x int) {
	write(x)
	fmt.Println()
}

func get(x int) int {
	if x == fa[x] {
		return x
	}
	f := get(fa[x])
	v[x] += v[fa[x]]
	fa[x] = f
	return f
}

func main() {
	n = read()
	m = read()
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	for i := 1; i <= m; i++ {
		l = read()
		r = read()
		vi = read()
		li := get(l)
		ri := get(r)
		if li != ri {
			v[ri] = vi - v[r] + v[l]
			fa[ri] = li
		} else {
			if v[r]-v[l] != vi {
				fmt.Println("No")
				return
			}
		}
	}
	fmt.Println("Yes")
}

// <END-OF-CODE>
