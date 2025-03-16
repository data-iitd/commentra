package main

import (
	"fmt"
)

const MAXN = 100005

var (
	N, M int
	H    [MAXN]int
	G    [MAXN][]int
)

func main() {
	fmt.Scan(&N, &M)
	for i := 0; i < N; i++ {
		fmt.Scan(&H[i])
	}
	for i := 0; i < M; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u-- // Convert to 0-based index
		v-- // Convert to 0-based index
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}

	ans := 0
	for u := 0; u < N; u++ {
		flag := true
		for _, v := range G[u] {
			if H[u] <= H[v] {
				flag = false
				break
			}
		}
		if flag {
			ans++
		}
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
