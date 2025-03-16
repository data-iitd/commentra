package main

import (
	"fmt"
)

func sum(k int64) int64 {
	ret := int64(0)
	pw := int64(10)
	length := int64(1)

	for {
		cur := min(pw-1, k)
		prev := pw / 10
		ret += (cur - prev + 1) * length
		if pw-1 >= k {
			break
		}
		length++
		pw *= 10
	}
	return ret
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	var w, m, k int64
	fmt.Scan(&w, &m, &k)

	lo := int64(0)
	hi := int64(1e18)

	for hi-lo > 1 {
		md := (lo + hi) / 2
		c := sum(m+md-1) - sum(m-1)
		if c*k <= w {
			lo = md
		} else {
			hi = md
		}
	}
	fmt.Println(lo)
}

// <END-OF-CODE>
