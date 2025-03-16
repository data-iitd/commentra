<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscanln(reader, &N)
	G := make([][]P, N)
	for i := 0; i < N; i++ {
		G[i] = make([]P, 0)
	}
	for i := 0; i < N-1; i++ {
		var u, v, w int
		fmt.Fscanln(reader, &u, &v, &w)
		G[u] = append(G[u], P{v, w})
		G[v] = append(G[v], P{u, w})
	}
	var L [100000]int
	var R [100000]int
	var U [22][100000]int
	var D [100000]int
	var Q int
	fmt.Fscanln(reader, &Q)
	for i := 0; i < Q; i++ {
		var q, x int
		fmt.Fscanln(reader, &q, &x)
		if q == 1 {
			var v int
			fmt.Fscanln(reader, &v)
			for i := 0; i < 22; i++ {
				U[i][v] = v
			}
			D[v] = 0
<<<<<<< HEAD
=======
			R[v] = 0
>>>>>>> 98c87cb78a (data updated)
			L[v] = 0
		} else {
			var v int
			fmt.Fscanln(reader, &v)
			var ans int
			for i := 20; i >= 0; i-- {
<<<<<<< HEAD
				if (x>>uint(i))&1 == 1 {
=======
				if (x>>i)&1 == 1 {
>>>>>>> 98c87cb78a (data updated)
					ans = max(ans, U[i][v])
					v = U[i][v]
				}
			}
			fmt.Println(ans)
		}
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

