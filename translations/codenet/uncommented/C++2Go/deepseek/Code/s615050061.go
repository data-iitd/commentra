package main

import (
	"fmt"
	"math/big"
)

type u64 uint64

const B = u64(13131)
const N = 500000 + 7

var n int
var s [N]byte
var f [N]u64
var g [N]int
var m map[u64]u64
var cnt u64

func pow(a, k u64) u64 {
	if k < 0 {
		k += (u64(1) << 63) - 1
	}
	t := u64(1)
	for k > 0 {
		if k&1 == 1 {
			t *= a
		}
		a *= a
		k >>= 1
	}
	return t
}

func main() {
	//	freopen("code.in", "r", stdin);
	//	freopen("code.out", "w", stdout);

	fmt.Scanf("%d%s", &n, &s[1])
	for i := 1; i <= n; i++ {
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i-1] + (u64(int(s[i] == '+')) - u64(int(s[i] == '-'))) * pow(B, u64(g[i]=g[i-1]))
		} else {
			f[i] = f[i-1]
			g[i] = g[i-1] + (int(s[i] == '<') - int(s[i] == '>'))
		}
	}
	m = make(map[u64]u64)
	for i := n; i > 0; i-- {
		m[f[i]]++
		cnt += m[f[n]*pow(B, u64(g[i-1]))+f[i-1]]
	}
	fmt.Printf("%d\n", cnt)
}

