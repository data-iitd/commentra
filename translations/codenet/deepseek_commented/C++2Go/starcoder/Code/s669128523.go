<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	WHITE = 0
	GRAY  = 1
	BLACK = 2
)

var (
	n   int
	M   [][]int
	d   []int
	f   []int
	tt  int
	col []int
)

func dfs_visit(u int) {
	var v int
	col[u] = GRAY
	d[u] = tt
	for v = 0; v < n; v++ {
		if M[u][v] == 0 {
			continue
		}
		if col[v] == WHITE {
			dfs_visit(v)
		}
	}
	col[u] = BLACK
	f[u] = tt
	tt++
}

func dfs() {
	var u, v int
	for i := 0; i < n; i++ {
		col[i] = WHITE
	}
	tt = 0

	for u = 0; u < n; u++ {
		if col[u] == WHITE {
			dfs_visit(u)
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var k, u, v int
	fmt.Fscan(os.Stdin, &n)
	M = make([][]int, n)
	for i := 0; i < n; i++ {
		M[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0
		}
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(os.Stdin, &u, &k)
		u--
		for j := 0; j < k; j++ {
			fmt.Fscan(os.Stdin, &v)
			v--
			M[u][v] = 1
		}
	}

	dfs()
}

