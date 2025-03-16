package main

import (
	"fmt"
	"math"
	"sort"
)

const mod = 1000000007
const mod9 = 998244353
const eps = 1e-7
const INF = 0x3f3f3f3f
const inf = 0x3f3f3f3f3f3f3f3f

func main() {
	var tc, n, m, fl int
	fmt.Scan(&tc, &n, &m)
	if n > m {
		n, m = m, n
	}
	for i := 1; i <= m; i++ {
		if i*tc >= n && i*tc <= m {
			fmt.Println("OK")
			fl = 1
			break
		}
	}
	if fl == 0 {
		fmt.Println("NG")
	}
}

