package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type P struct {
	a, b int
}

const (
	INF  = 1145141919
	MOD  = 1000000007
	MAX_L = 22
)

var (
	N int
	G [100000][]P
	U [MAX_L][100000]int
	R [100000]int
	L [100000]int64
)

func dfs(x, p, r int, l int64) {
	U[0][x] = p
	R[x] = r
	L[x] = l
	for _, pp := range G[x] {
		t := pp.a
		if t == p {
			continue
		}
		dfs(t, x, r+1, l+int64(pp.b))
	}
}

func lca(a, b int) int {
	if R[a] > R[b] {
		a, b = b, a
	}
	for k := 0; k < MAX_L; k++ {
		if (R[a]-R[b])>>k&1 != 0 {
			b = U[k][b]
		}
	}
	if a == b {
		return a
	}
	for k := MAX_L - 1; k >= 0; k-- {
		if U[k][a] != U[k][b] {
			a = U[k][a]
			b = U[k][b]
		}
	}
	return U[0][a]
}

func dist(x, y int) int64 {
	g := lca(x, y)
	return L[x] + L[y] - 2*L[g]
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())

	G = make([][]P, N)
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		var a, b, c int
		fmt.Sscanf(scanner.Text(), "%d %d %d", &a, &b, &c)
		a--
		b--
		G[a] = append(G[a], P{b, c})
		G[b] = append(G[b], P{a, c})
	}

	for i := 0; i < MAX_L; i++ {
		for j := 0; j < N; j++ {
			U[i][j] = -1
		}
	}

	dfs(0, -1, 0, 0)

	for i := 0; i < MAX_L-1; i++ {
		for v := 0; v < N; v++ {
			if U[i][v] == -1 {
				U[i+1][v] = -1
			} else {
				U[i+1][v] = U[i][U[i][v]]
			}
		}
	}

	scanner.Scan()
	var Q, K int
	fmt.Sscanf(scanner.Text(), "%d %d", &Q, &K)
	K--

	for i := 0; i < Q; i++ {
		scanner.Scan()
		var x, y int
		fmt.Sscanf(scanner.Text(), "%d %d", &x, &y)
		x--
		y--
		fmt.Fprintln(writer, dist(x, K)+dist(K, y))
	}
}

