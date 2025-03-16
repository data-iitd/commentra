package main

import (
	"fmt"
	"sort"
)

func read() int {
	var x int
	fmt.Scanf("%d", &x)
	return x
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
			q[++tot] = a[i]
			i++
		}
	}
	writeln(q[tot] * q[tot-1])
}

