
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

func main() {
	var (
		n, x, y, z int
		i, j       int
		g          [101][101]int
		d          [101]int
		f          [101]int
		color      [101]int
		time       int
	)

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)

	for i = 0; i < n; i++ {
		fmt.Fscan(reader, &x, &y)
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
		for j = 0; j < y; j++ {
			fmt.Fscan(reader, &z)
			g[x-1][z-1] = 1
		}
	}

	time = 0
	for i = 0; i < n; i++ {
		if color[i] == 0 {
			visit(i)
		}
	}

	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func visit(u int) {
	var i int
<<<<<<< HEAD
	color[u] = 1
	d[u] = time
	time++
=======

	color[u] = 1
	d[u] = time
	time++

>>>>>>> 98c87cb78a (data updated)
	for i = 0; i < n; i++ {
		if g[u][i] == 0 {
			continue
		}
		if color[i] == 0 {
			visit(i)
		}
	}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
	color[u] = 2
	f[u] = time
	time++
}

