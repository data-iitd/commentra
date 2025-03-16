package main

import (
	"fmt"
	"sort"
	"strings"
)

type Edge struct {
	p int64  // destination vertex
	i int64  // index of the edge in the data array
	s string // source string
}

type BySourceAndDest []Edge

func (a BySourceAndDest) Len() int           { return len(a) }
func (a BySourceAndDest) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a BySourceAndDest) Less(i, j int) bool {
	if a[i].s != a[j].s {
		return a[i].s < a[j].s // compare source strings first
	}
	return a[i].p > a[j].p // if source strings are equal, compare destination vertices
}

func main() {
	var n int64
	fmt.Scan(&n) // read the number of vertices
	data := make([]Edge, n)

	for i := int64(0); i < n; i++ { // for each vertex
		var s string
		var p int64
		fmt.Scan(&s, &p) // read the source string and destination vertex
		data[i] = Edge{s: s, p: p, i: i} // assign the edge
	}

	sort.Sort(BySourceAndDest(data)) // sort the edges based on their source strings and destination vertices

	for i := int64(0); i < n; i++ {
		fmt.Println(data[i].i + 1) // print the indices of the sorted edges
	}
}

// <END-OF-CODE>
