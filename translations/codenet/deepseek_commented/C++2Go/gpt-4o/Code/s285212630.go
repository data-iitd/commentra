package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX_L = 22
	INF   = 1145141919
)

type Pair struct {
	first  int64
	second int64
}

var (
	N int64
	G [100000][]Pair
	U [MAX_L][100000]int64
	R [100000]int64
	L [100000]int64
)

func dfs(x, p, r int64, l int64) {
	U[0][x] = p
	R[x] = r
	L[x] = l
	for _, pp := range G[x] {
		t := pp.first
		if t == p {
			continue
		}
		dfs(t, x, r+1, l+pp.second)
	}
}

func lca(a, b int64) int64 {
	if R[a] > R[b] {
		a, b = b, a
	}
	for k := 0; k < MAX_L; k++ {
		if (R[a]-R[b])>>k&1 == 1 {
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

func dist(x, y int64) int64 {
	g := lca(x, y)
	return L[x] + L[y] - 2*L[g]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &N)
	for i := int64(0); i < N-1; i++ {
		var a, b, c int64
		fmt.Fscan(reader, &a, &b, &c)
		a--
		b--
		G[a] = append(G[a], Pair{b, c})
		G[b] = append(G[b], Pair{a, c})
	}
	for i := 0; i < MAX_L; i++ {
		for j := int64(0); j < N; j++ {
			U[i][j] = -1
		}
	}
	dfs(0, -1, 0, 0)
	for i := 0; i < MAX_L-1; i++ {
		for v := int64(0); v < N; v++ {
			if U[i][v] == -1 {
				U[i+1][v] = -1
			} else {
				U[i+1][v] = U[i][U[i][v]]
			}
		}
	}
	var Q, K int64
	fmt.Fscan(reader, &Q, &K)
	K--
	for i := int64(0); i < Q; i++ {
		var x, y int64
		fmt.Fscan(reader, &x, &y)
		x--
		y--
		fmt.Println(dist(x, K) + dist(K, y))
	}
}

// <END-OF-CODE>
