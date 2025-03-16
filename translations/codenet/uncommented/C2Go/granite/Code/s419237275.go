
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

#define N 200
#define SHIRO 0
#define HAI 1
#define KURO 2

func main() {
	var n int
	var err error
	var u, k, v int
	var i, j int

	reader := bufio.NewReader(os.Stdin)

	fmt.Fscanf(reader, "%d\n", &n)

	A := make([][]int, n)
	for i = 0; i < n; i++ {
		A[i] = make([]int, n)
	}
	for i = 0; i < n; i++ {
		fmt.Fscanf(reader, "%d %d\n", &u, &k)
		u--
		for j = 0; j < k; j++ {
			fmt.Fscanf(reader, "%d\n", &v)
			v--
			A[u][v] = 1
		}
	}

	color := make([]int, n)
	d := make([]int, n)
	f := make([]int, n)

	for i = 0; i < n; i++ {
		color[i] = SHIRO
	}

	TT := 0

	for u = 0; u < n; u++ {
		if color[u] == SHIRO {
			bbbb(u, A, color, d, f, &TT)
		}
	}

	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func bbbbb(k int, A [][]int, color []int, d []int, f []int, TT *int) {
	var v int
	color[k] = HAI
	*TT++
	d[k] = *TT
	for v = 0; v < n; v++ {
		if A[k][v] == 0 {
			continue
		}
		if color[v] == SHIRO {
			bbbb(v, A, color, d, f, TT)
		}
	}
	color[k] = KURO
	f[k] = *TT + 1
}

