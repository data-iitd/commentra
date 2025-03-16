#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#ifdef __cplusplus
#include <bits/stdc++.h>
#endif

func nextint() int32 {
	var c byte = getchar_unlocked()
	for c != '-' && (c < '0' || '9' < c) {
		c = getchar_unlocked()
	}
	var s bool = false
	if c == '-' {
		s = true
		c = getchar_unlocked()
	}
	var x uint32 = 0
	for '0' <= c && c <= '9' {
		x = x*10 + uint32(c-'0')
		c = getchar_unlocked()
	}
	if s {
		return -int32(x)
	}
	return int32(x)
}

var n int

func p(a, b int) int {
	if a < b {
		return a + b*n
	}
	return b + a*n
}

var a [1000][999]int

var e1 [1000000]int
var e2 [1000000]int
var d [1000000]int
var b [1000000]bool

func f(from int) int {
	if b[from] {
		return -1
	}
	if d[from] != 0 {
		return d[from]
	}
	b[from] = true
	var to int
	to = e1[from]
	var max int = 0
	if to != 0 {
		var now int = f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	to = e2[from]
	if to != 0 {
		var now int = f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	b[from] = false
	return d[from] = max + 1
}

func main() {
	n = nextint()
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			a[i][j] = nextint() - 1
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
				fmt.Println("-1")
				return
			}
		}
	}
	var ans int = 0
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

