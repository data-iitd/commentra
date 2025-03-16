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

// <START-OF-CODE>

const (
	MAX = 101
	WHITE = 0
	BLACK = 2
	GRAY = 1
)

var (
	time int
	n int
	g [MAX][MAX] = [MAX][MAX]{}
	d [MAX]
	f [MAX]
	color [MAX] = [MAX]{}
)

func visit(u int) {
	var i int
<<<<<<< HEAD

	color[u] = GRAY
	d[u] = time
	time++

=======
	color[u] = GRAY
	d[u] = time
	time++
>>>>>>> 98c87cb78a (data updated)
	for i = 0; i < n; i++ {
		if g[u][i] == 0 {
			continue
		}
		if color[i] == WHITE {
			visit(i)
		}
	}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
	color[u] = BLACK
	f[u] = time
	time++
}

func dfs() {
	var i int
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
	time = 0
	for i = 0; i < n; i++ {
		if color[i] == WHITE {
			visit(i)
		}
	}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var i, j, x, y, z int
<<<<<<< HEAD

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d", &n)

	for i = 0; i < n; i++ {
		fmt.Fscanf(reader, "%d %d", &x, &y)
		for j = 0; j < y; j++ {
			fmt.Fscanf(reader, "%d", &z)
			g[x-1][z-1] = 1
		}
	}

=======
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &x, &y)
		for j = 0; j < y; j++ {
			fmt.Scanf("%d", &z)
			g[x-1][z-1] = 1
		}
	}
>>>>>>> 98c87cb78a (data updated)
	dfs()
}

// 