package main

import (
	"fmt"
	"sort"
)

const mod = 1e9 + 7
const INF = 1e18 + 1

var n int
var k int64
var a []int64

func main() {
	var fs = bufio.NewReader(os.Stdin)
	fmt.Fscan(fs, &n, &k)
	a = make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(fs, &a[i])
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})

	l, r := -INF, INF
	for l+1 < r {
		c := (l + r) / 2
		if check(c) {
			l = c
		} else {
			r = c
		}
	}
	fmt.Println(l)
}

func check(x int64) bool {
	tot := int64(0)
	for i := 0; i < n; i++ {
		now := a[i]
		l, r := 0, n
		if now >= 0 {
			for l < r {
				c := (l + r) / 2
				if now*a[c] < x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(l)
		} else {
			for l < r {
				c := (l + r) / 2
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
	return tot/2 < k
}

// <END-OF-CODE>
