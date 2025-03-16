<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"sort"
)

const B = 13131
const N = 500000 + 7

var n int
var s [N]byte
var f [N]uint64
var g [N]int
var map map[uint64]uint64
var cnt uint64

func pow(a, k uint64) uint64 {
	if k < 0 {
		k += math.MaxUint64
	}
	t := uint64(1)
	for ; k > 0; a, k = a*a, k>>1 {
		if k&1 == 1 {
			t *= a
		}
	}
	return t
}

func main() {
	fmt.Scanf("%d%s", &n, s[1:])
	for i := 1; i <= n; i++ {
		if s[i] == '+' || s[i] == '-' {
			f[i] = f[i-1] + uint64(s[i] == '+'-1)*pow(B, g[i] = g[i-1])
		} else {
			f[i] = f[i-1]
			g[i] = g[i-1] + int(s[i] == '<'-1)
		}
	}
	for i := n; i > 0; i-- {
		map[f[i]]++
		cnt += map[f[n]*pow(B, g[i-1])+f[i-1]]
	}
	fmt.Println(cnt)
}

