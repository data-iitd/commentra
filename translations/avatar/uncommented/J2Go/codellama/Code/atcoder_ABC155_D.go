
package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n int
	var k int64
	var a [100000]int64
	fmt.Scan(&n, &k)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Slice(a[:n], func(i, j int) bool {
		return a[i] < a[j]
	})
	var INF int64 = int64(math.Pow(10, 18)) + 1
	var l int64 = -INF
	var r int64 = INF
	for l+1 < r {
		var c int64 = (l + r) / 2
		if check(c) {
			l = c
		} else {
			r = c
		}
	}
	fmt.Println(l)
}

func check(x int64) bool {
	var tot int64 = 0
	for i := 0; i < n; i++ {
		var now int64 = a[i]
		var l int = 0
		var r int = n
		if now >= 0 {
			for l < r {
				var c int = (l + r) / 2
				if now*a[c] < x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(l)
		} else {
			for l < r {
				var c int = (l + r) / 2
				if now*a[c] >= x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(n - l)
		}
		if now*now < x {
			tot--
		}
	}
	if tot/2 < k {
		return true
	} else {
		return false
	}
}

