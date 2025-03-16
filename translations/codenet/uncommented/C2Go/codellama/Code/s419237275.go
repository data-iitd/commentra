
package main

import (
	"fmt"
)

const (
	N = 200
	SHIRO = 0
	HAI = 1
	KURO = 2
)

var (
	n int
	A [N][N]int
	color [N]int
	d [N]int
	f [N]int
	TT int
)

func aaaaa() {
	var u,k,v int
	var i,j int

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
	f[k] = ++TT
}

func main() {
	var u,k,v int
	var i,j int

	fmt.Scanf("%d", &n)

	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			A[i][j] = 0
		}
	}
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &u, &k)
		u--
		for j = 0; j < k; j++ {
			fmt.Scanf("%d", &v)
			v--
			A[u][v] = 1
		}
	}

	aaaaa()
}

