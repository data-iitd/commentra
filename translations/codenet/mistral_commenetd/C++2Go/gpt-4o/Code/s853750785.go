package main

import (
	"fmt"
)

const MOD = 1e9 + 7

type mint struct {
	x int64
}

func (a mint) add(b mint) mint {
	a.x += b.x
	if a.x >= MOD {
		a.x -= MOD
	}
	return a
}

func (a mint) sub(b mint) mint {
	a.x += MOD - b.x
	if a.x >= MOD {
		a.x -= MOD
	}
	return a
}

func (a mint) mul(b mint) mint {
	a.x = (a.x * b.x) % MOD
	return a
}

func (a mint) pow(t int64) mint {
	if t == 0 {
		return mint{1}
	}
	res := a.pow(t >> 1)
	res = res.mul(res)
	if t&1 == 1 {
		res = res.mul(a)
	}
	return res
}

func (a mint) inv() mint {
	return a.pow(MOD - 2)
}

func (a mint) div(b mint) mint {
	return a.mul(b.inv())
}

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
		u-- // Convert to 0-indexing
		v-- // Convert to 0-indexing
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}

	ans := int64(0)
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
