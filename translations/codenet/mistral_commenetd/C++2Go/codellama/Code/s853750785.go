
package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	H := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&H[i])
	}
	G := make([][]int, N)
	for i := 0; i < M; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}
	ans := 0
	for u := 0; u < N; u++ {
		flag := true
		for _, v := range G[u] {
			if H[u] <= H[v] {
				flag = false
			}
		}
		if flag {
			ans++
		}
	}
	fmt.Println(ans)
}

