package main

import (
	"fmt"
	"math"
)

const (
	MOD = 1e9 + 7
)

type mint struct {
	x int
}

func (m mint) String() string {
	return fmt.Sprintf("%d", m.x)
}

func (m *mint) add(a mint) {
	m.x = (m.x + a.x) % int(MOD)
}

func (m *mint) sub(a mint) {
	m.x = (m.x + MOD - a.x) % int(MOD)
}

func (m *mint) mul(a mint) {
	m.x = (m.x * a.x) % int(MOD)
}

func (m mint) pow(t int) mint {
	if t == 0 {
		return mint{1}
	}
	a := m.pow(t / 2)
	a.mul(a)
	if t%2 == 1 {
		a.mul(m)
	}
	return a
}

func (m mint) inv() mint {
	return m.pow(int(MOD) - 2)
}

func (m *mint) div(a mint) {
	m.mul(a.inv())
}

type combination struct {
	fact, ifact []mint
}

func newCombination(n int) *combination {
	fact := make([]mint, n+1)
	ifact := make([]mint, n+1)
	fact[0] = mint{1}
	for i := 1; i <= n; i++ {
		fact[i].mul(fact[i-1])
	}
	ifact[n] = fact[n]
	for i := n; i > 0; i-- {
		ifact[i-1].mul(ifact[i])
	}
	return &combination{fact, ifact}
}

func (c combination) comb(n, k int) mint {
	if k < 0 || k > n {
		return mint{0}
	}
	return c.fact[n].mul(c.ifact[k]).mul(c.ifact[n-k])
}

func f(n, k int) mint {
	if n < 0 {
		return mint{0}
	}
	c := newCombination(1000005)
	res := c.comb(n, k)
	res.mul(c.fact[k])
	return res
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
				break
			}
		}
		if flag {
			ans++
		}
	}
	fmt.Println(ans)
}

