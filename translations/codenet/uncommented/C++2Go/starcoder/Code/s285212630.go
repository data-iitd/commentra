package main

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
		var a, b, c int
		fmt.Fscanln(reader, &a, &b, &c)
		a--
		b--
		G[a] = append(G[a], P{b, c})
		G[b] = append(G[b], P{a, c})
	}
	var Q, K int
	fmt.Fscanln(reader, &Q, &K)
	K--
	U := make([][]int, 22)
	for i := 0; i < 22; i++ {
		U[i] = make([]int, N)
	}
	for i := 0; i < 22; i++ {
		for j := 0; j < N; j++ {
			U[i][j] = -1
		}
	}
	var dfs func(int, int, int, int)
	dfs = func(x, p, r, l int) {
		U[0][x] = p
		U[1][x] = r
		U[2][x] = l
		for _, pp := range G[x] {
			t := pp._1
			if t == p {
				continue
			}
			dfs(t, x, r+1, l+pp._2)
		}
	}
	dfs(0, -1, 0, 0)
	for i := 2; i < 22; i++ {
		for j := 0; j < N; j++ {
			if U[i-1][j] == -1 {
				U[i][j] = -1
			} else {
				U[i][j] = U[i-1][U[i-1][j]]
			}
		}
	}
	for i := 0; i < Q; i++ {
		var x, y int
		fmt.Fscanln(reader, &x, &y)
		x--
		y--
		var ans int
		for j := 0; j < 22; j++ {
			if U[j][x] == -1 {
				continue
			}
			if U[j][y] == -1 {
				continue
			}
			if U[j][x] == U[j][y] {
				ans += U[j][x]
			}
		}
		fmt.Println(ans)
	}
}

