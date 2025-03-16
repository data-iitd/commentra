package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scanf("%d", &a[i][j])
		}
	}
	e1 := make([]int, n*n)
	e2 := make([]int, n*n)
	d := make([]int, n*n)
	b := make([]bool, n*n)
	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			from := i*n + a[i][j]
			to := i*n + a[i][j+1]
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
		from := i*n + a[i][0]
		now := f(from)
		if now < 0 {
			fmt.Println(-1)
			return
		}
		if now > ans {
			ans = now
		}
	}
	fmt.Println(ans)
}

func f(from int) int {
	if b[from] {
		return -1
	}
	if d[from]!= 0 {
		return d[from]
	}
	b[from] = true
	var to int
	to = e1[from]
	max := 0
	if to!= 0 {
		now := f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	to = e2[from]
	if to!= 0 {
		now := f(to)
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

