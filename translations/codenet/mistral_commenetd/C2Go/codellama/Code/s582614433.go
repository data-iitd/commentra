package main

import (
	"fmt"
	"sort"
	"strings"
)

type E struct {
	p, i int
	s    string
}

func esort(a, b interface{}) int {
	p, q := a.(*E), b.(*E)
	if strings.Compare(p.s, q.s) != 0 {
		return strings.Compare(p.s, q.s)
	}
	if p.p < q.p {
		return 1
	}
	return -1
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	data := make([]E, n)
	for i := 0; i < n; i++ {
		fmt.Scanf(" %s%d", &data[i].s, &data[i].p)
		data[i].i = i
	}
	sort.Slice(data, esort)
	for i := 0; i < n; i++ {
		fmt.Println(data[i].i + 1)
	}
}

