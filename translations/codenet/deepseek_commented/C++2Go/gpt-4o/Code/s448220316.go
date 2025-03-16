package main

import (
	"fmt"
)

var (
	n, m, l, r, vi int
	fa             [100005]int
	v              [200005]int
)

// Read function to efficiently read integers.
func read() int {
	var k, f int = 0, 1
	var ch byte
	for {
		ch = getchar()
		if ch < '0' || ch > '9' {
			if ch == '-' {
				f = -1
			}
			continue
		}
		break
	}
	for {
		if ch >= '0' && ch <= '9' {
			k = k*10 + int(ch-'0')
			ch = getchar()
		} else {
			break
		}
	}
	return k * f
}

// getchar function to read a single byte from input.
func getchar() byte {
	var b [1]byte
	_, _ = fmt.Scan(b[:])
	return b[0]
}

// Get function to find the root of a node and update the value array.
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
