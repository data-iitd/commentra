package main

import (
	"fmt"
)

func gc() byte {
	var c byte
	fmt.Scanf("%c", &c)
	return c
}

func in() int { // Non-negative integer input
	n := 0
	c := gc()
	for c >= '0' {
		n = 10*n + int(c-'0')
		c = gc()
	}
	return n
}

var f1 [100]int
var f2 [100]int

func calc(n int) {
	k := n % 10
	for n >= 10 {
		n /= 10
	}
	f1[10*k+n]++
	f2[n*10+k]++
}

func main() {
	var N, ans int

	N = in()
	for N > 0 {
		calc(N)
		N--
	}

	ans = 0
	for i := 0; i < 100; i++ {
		ans += f1[i] * f2[i]
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
