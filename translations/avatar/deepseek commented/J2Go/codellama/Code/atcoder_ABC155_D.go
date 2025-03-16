package main

import (
	"fmt"
	"math"
	"sort"
)

const mod = 1e9 + 7

var n int
var k int64
var a []int64

func main() {
	var fs = bufio.NewScanner(os.Stdin)
	fs.Scan()
	n = fs.Text()
	fs.Scan()
	k = fs.Text()
	a = make([]int64, n)
	for i := 0; i < n; i++ {
		fs.Scan()
		a[i] = fs.Text()
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
	var INF = int64(math.Pow(10, 18)) + 1
	var l = -INF
	var r = INF
	for l+1 < r {
		var c = (l + r) / 2
		if check(c) {
			l = c
		} else {
			r = c
		}
	}
	fmt.Println(l)
}

func check(x int64) bool {
	var tot int64
	for i := 0; i < n; i++ {
		var now = a[i]
		var l = 0
		var r = n
		if now >= 0 {
			for l < r {
				var c = (l + r) / 2
				if now*a[c] < x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += l
		} else {
			for l < r {
				var c = (l + r) / 2
				if now*a[c] >= x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += (n - l)
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

