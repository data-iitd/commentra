package main

import (
	"fmt"
	"sort"
)

type Edge struct {
	p int64
	i int
	s string
}

type ByEdge []Edge

func (a ByEdge) Len() int           { return len(a) }
func (a ByEdge) Less(i, j int) bool {
	if a[i].s != a[j].s {
		return a[i].s < a[j].s
	}
	if a[i].p != a[j].p {
		return a[i].p > a[j].p
	}
	return false
}
func (a ByEdge) Swap(i, j int) { a[i], a[j] = a[j], a[i] }

func main() {
	var n int64
	fmt.Scan(&n)
	data := make([]Edge, n)

	for i := int64(0); i < n; i++ {
		var p int64
		var s string
		fmt.Scan(&s, &p)
		data[i] = Edge{p: p, i: int(i), s: s}
	}

	sort.Sort(ByEdge(data))

	for _, edge := range data {
		fmt.Println(edge.i + 1)
	}
}

// <END-OF-CODE>
