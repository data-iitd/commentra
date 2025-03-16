package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	"strconv"
)

type P struct {
	name string
	t int
}

func main() {
	var n, q int
	var a P
	var T int
	var Q [100005]P
	var head, tail int

	fmt.Scanf("%d %d", &n, &q)

	for i := 0; i < n; i++ {
		fmt.Scanf("%s%d", &a.name, &a.t)
		Q[tail] = a
		tail++
	}

	for n!= 0 {
		a = Q[head]
		if a.t > q {
			a.t = a.t - q
			T += q
			Q[tail] = a
			tail++
		} else {
			T = T + a.t
			fmt.Printf("%s %d\n", a.name, T)
			n--
		}
		head++
	}
}

