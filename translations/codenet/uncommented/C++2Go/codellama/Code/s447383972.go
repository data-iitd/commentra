package main

import (
	"fmt"
	"sort"
)

func read() int {
	var x, f int
	ch := ' '
	for ch < '0' || ch > '9' {
		if ch == '-' {
			f = -1
		}
		ch = ' '
	}
	for ch >= '0' && ch <= '9' {
		x = x*10 + ch - '0'
		ch = ' '
	}
	return x * f
}

func write(x int) {
	if x < 0 {
		fmt.Printf("-")
		x = -x
	}
	if x >= 10 {
		write(x / 10)
	}
	fmt.Printf("%d", x%10)
}

func writeln(x int) {
	write(x)
	fmt.Println()
}

func main() {
	n := read()
	a := make([]int, n+1)
	For(i, 1, n) {
		a[i] = read()
	}
	sort.Ints(a[1:])
	tot := 0
	For(i, 1, n) {
		if a[i] == a[i+1] {
			a[++tot] = a[i]
			i++
		}
	}
	writeln(a[tot] * a[tot-1])
}

