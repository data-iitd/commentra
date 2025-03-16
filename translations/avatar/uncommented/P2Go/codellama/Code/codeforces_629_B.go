package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)
	m := make([]int, N)
	f := make([]int, N)
	for i := 0; i < N; i++ {
		m[i] = 0
		f[i] = 0
	}
	for i := 0; i < int(input()); i++ {
		x, a, b := input()
		a, _ = strconv.Atoi(a)
		b, _ = strconv.Atoi(b)
		b++
		if x == "M" {
			m[a] += 2
			m[b] -= 2
		} else {
			f[a] += 2
			f[b] -= 2
		}
	}
	a, b, c := 0, 0, 0
	for i := 0; i < N; i++ {
		a += m[i]
		b += f[i]
		if a < c {
			c = a
		}
		if b < c {
			c = b
		}
	}
	fmt.Println(c)
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

