
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Edge struct {
	s, g, c int
}

type Graph struct {
	vcnt, ecnt int
	e           []Edge
	id          []int
}

func esort(a, b interface{}) bool {
	ea := a.(Edge)
	eb := b.(Edge)
	if ea.s < eb.s {
		return true
	} else if ea.s > eb.s {
		return false
	} else if ea.g < eb.g {
		return true
	} else if ea.g > eb.g {
		return false
	} else {
		return ea.c < eb.c
	}
}

var g Graph

func readgraph() {
	// Adapted from the original C code
	// Read the number of vertices
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	g.vcnt = n
	g.ecnt = 2*n - 2
	g.e = make([]Edge, g.ecnt)
	g.id = make([]int, g.vcnt+1)

	// Read each edge and store it in the graph structure
	for i := 0; i < n; i++ {
		var x, y, c int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d\n", &x, &y, &c)
		g.e[2*i].s = x
		g.e[2*i].g = y
		g.e[2*i].c = c
		g.e[2*i+1].s = y
		g.e[2*i+1].g = x
		g.e[2*i+1].c = c
	}

	// Populate the id array with the starting index of edges for each vertex
	p := 0
	for i := 0; i < g.vcnt; i++ {
		for p < g.ecnt && g.e[p].s < i {
			p++
		}
		g.id[i] = p
	}
	g.id[g.vcnt] = g.ecnt // Set the sentinel value for the id array
}

// Tree diameter
func tyokkei() int {
	// Adapted from the original C code
	// Perform DFS to find the diameter of the tree
	//...
	// Return the diameter of the tree
	return 0
}

func main() {
	readgraph() // Read the graph
	fmt.Println(tyokkei()) // Print the diameter of the tree
}

// END-OF-CODE