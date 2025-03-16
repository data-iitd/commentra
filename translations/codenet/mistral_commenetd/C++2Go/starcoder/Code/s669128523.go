<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	N = 100
)

var (
	M  [N][N]int
	n  int
	tt int
<<<<<<< HEAD
=======
	d  [N]int
	f  [N]int
	c  [N]int
>>>>>>> 98c87cb78a (data updated)
)

func main() {
	var (
		u, v, k int
		i       int
	)

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)

	for i = 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0
		}
	}

	for i = 0; i < n; i++ {
		fmt.Fscan(reader, &u, &k)
		u--
		for j := 0; j < k; j++ {
			fmt.Fscan(reader, &v)
			v--
			M[u][v] = 1
		}
	}

	for i = 0; i < n; i++ {
<<<<<<< HEAD
		for j := 0; j < n; j++ {
			color[j] = WHITE
		}
		tt = 0
		if color[i] == WHITE {
=======
		c[i] = 0
	}

	tt = 0

	for i = 0; i < n; i++ {
		if c[i] == 0 {
>>>>>>> 98c87cb78a (data updated)
			dfs_visit(i)
		}
	}

	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func dfs_visit(u int) {
	var (
		v int
	)

<<<<<<< HEAD
	color[u] = GRAY
	d[u] = tt + 1
=======
	c[u] = 1
	d[u] = tt + 1
	tt++

>>>>>>> 98c87cb78a (data updated)
	for v = 0; v < n; v++ {
		if M[u][v] == 0 {
			continue
		}
<<<<<<< HEAD
		if color[v] == WHITE {
			dfs_visit(v)
		}
	}
	color[u] = BLACK
	f[u] = tt + 1
=======
		if c[v] == 0 {
			dfs_visit(v)
		}
	}

	c[u] = 2
	f[u] = tt + 1
	tt++
>>>>>>> 98c87cb78a (data updated)
}

