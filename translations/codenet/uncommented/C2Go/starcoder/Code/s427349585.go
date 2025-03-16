package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type card struct {
	s string
	v int
}

func main() {
	var n int
	var a, b []card
	var i, v int
	var s string
	var stable bool

	fmt.Scanf("%d\n", &n)

	a = make([]card, n)
	b = make([]card, n)

	for i = 0; i < n; i++ {
		fmt.Scanf("%s %d\n", &s, &v)
		a[i] = card{s, v}
		b[i] = card{s, v}
	}

	sort.Slice(a, func(i, j int) bool { return a[i].v < a[j].v })
	sort.Slice(b, func(i, j int) bool { return b[i].s < b[j].s })

	stable = true
	for i = 0; i < n; i++ {
		if a[i].s!= b[i].s {
			stable = false
		}
	}

	if stable {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}

	for i = 0; i < n; i++ {
		fmt.Printf("%s %d\n", b[i].s, b[i].v)
	}
}

