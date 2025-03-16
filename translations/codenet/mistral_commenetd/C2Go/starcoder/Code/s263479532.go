
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
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of vertices: ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the adjacency matrix: ")
	G := make([][]int, n)
	for i := 0; i < n; i++ {
		G[i] = make([]int, n)
		for j := 0; j < n; j++ {
			G[i][j], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		}
	}
<<<<<<< HEAD
	fmt.Println(prim(G, n))
=======
	fmt.Println("The total weight of the MST is: ", prim(G, n))
>>>>>>> 98c87cb78a (data updated)
}

func prim(G [][]int, n int) int {
	var (
<<<<<<< HEAD
		u, v, mincost int
		i, j           int
		d              = make([]int, n)
		pi             = make([]int, n)
		color          = make([]int, n)
		sum            = 0
	)
	for u = 0; u < n; u++ {
		d[u] = INF
		pi[u] = NIL
		color[u] = WHITE
	}
	d[0] = 0
	for {
		mincost = INF
		for i = 0; i < n; i++ {
			if color[i]!= BLACK && d[i] < mincost {
=======
		u, v, mincost, sum int
		i, j                int
	)
	d := make([]int, n)
	pi := make([]int, n)
	color := make([]int, n)
	for u = 0; u < n; u++ {
		d[u] = 999999
		pi[u] = -1
		color[u] = 0
	}
	d[0] = 0
	for {
		mincost = 999999
		for i = 0; i < n; i++ {
			if color[i] == 0 && d[i] < mincost {
>>>>>>> 98c87cb78a (data updated)
				mincost = d[i]
				u = i
			}
		}
<<<<<<< HEAD
		if mincost == INF {
			break
		}
		color[u] = BLACK
		for v = 0; v < n; v++ {
			if color[v]!= BLACK && G[u][v] < d[v] && G[u][v]!= -1 {
=======
		if mincost == 999999 {
			break
		}
		color[u] = 1
		for v = 0; v < n; v++ {
			if color[v] == 0 && G[u][v] < d[v] {
>>>>>>> 98c87cb78a (data updated)
				pi[v] = u
				d[v] = G[u][v]
			}
		}
	}
	for i = 0; i < n; i++ {
<<<<<<< HEAD
		if d[i]!= INF {
=======
		if d[i]!= 999999 {
>>>>>>> 98c87cb78a (data updated)
			sum += d[i]
		}
	}
	return sum
}

