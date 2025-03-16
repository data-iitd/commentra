package main

import (
	"fmt"
	"math"
)

var n int
var a [1000][999]int
var e1 [1000000]int
var e2 [1000000]int
var d [1000000]int
var b [1000000]bool

func nextInt() int {
	var x int
	_, err := fmt.Scan(&x)
	if err != nil {
		panic(err)
	}
	return x - 1 // Adjusting to zero-based index
}

func p(a, b int) int {
	if a < b {
		return a + b*n
	}
	return b + a*n
}

func f(from int) int {
	if b[from] {
		return -1
	}
	if d[from] != 0 {
		return d[from]
	}
	b[from] = true
	max := 0

	to := e1[from]
	if to != 0 {
		now := f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}

	to = e2[from]
	if to != 0 {
		now := f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}

	b[from] = false
	d[from] = max + 1
	return d[from]
}

func main() {
	n = nextInt()
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			a[i][j] = nextInt()
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			from := p(i, a[i][j])
			to := p(i, a[i][j+1])
			if e1[from] == 0 {
				e1[from] = to
			} else if e2[from] == 0 {
				e2[from] = to
			} else {
				fmt.Println(-1)
				return
			}
		}
	}

	ans := 0
	for i := 0; i < n; i++ {
		from := p(i, a[i][0])
		now := f(from)
		if now < 0 {
			ans = -1
			break
		}
		if now > ans {
			ans = now
		}
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
