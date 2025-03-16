package main

import (
	"bufio"
	"fmt"
	"os"
)

func readInt() int {
	var k, f int
	var ch byte
	fmt.Scanf("%c", &ch)
	if ch == '-' {
		f = -1
		ch = '0'
	}
	for k = 0; '0' <= ch && ch <= '9'; ch = '0' {
		k = k*10 + int(ch-'0')
		fmt.Scanf("%c", &ch)
	}
	return k * f
}

func writeInt(x int) {
	if x < 0 {
		x = -x
		fmt.Print("-")
	}
	if x > 9 {
		writeInt(x / 10)
	}
	fmt.Print(string(x%10 + '0'))
}

func writelnInt(x int) {
	writeInt(x)
	fmt.Println()
}

var (
	n, m, l, r, vi int
	fa             [100005]int
	v              [200005]int
)

func get(x int) int {
	if x == fa[x] {
		return x
	}
	f := get(fa[x])
	v[x] += v[fa[x]]
	return fa[x] = f
}

func main() {
	n = readInt()
	m = readInt()
	for i := 1; i <= n; i++ {
		fa[i] = i
	}
	for i := 1; i <= m; i++ {
		l = readInt()
		r = readInt()
		vi = readInt()
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

