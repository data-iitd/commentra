package main

import (
	"fmt"
)

const (
	N      = 200
	SHIRO  = 0
	HAI    = 1
	KURO   = 2
)

func aaaaa() {
	var u, i int

	for i = 0; i < n; i++ {
		color[i] = SHIRO
	}

	TT = 0

	for u = 0; u < n; u++ {
		if color[u] == SHIRO {
			bbbbb(u)
		}
	}

	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func bbbbb(k int) {
	var v int
	color[k] = HAI
	TT++
	d[k] = TT
	for v = 0; v < n; v++ {
		if A[k][v] == 0 {
			continue
		}
		if color[v] == SHIRO {
			bbbbb(v)
		}
	}
	color[k] = KURO
	f[k] = TT + 1
	TT++
}

var n int
var A [N][N]int
var color [N]int
var d [N]int
var f [N]int
var TT int

func main() {
	var u, k, v, i, j int

	fmt.Scan(&n)

	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			A[i][j] = 0
		}
	}
	for i = 0; i < n; i++ {
		fmt.Scan(&u, &k)
		u--
		for j = 0; j < k; j++ {
			fmt.Scan(&v)
			v--
			A[u][v] = 1
		}
	}

	aaaaa()
}

