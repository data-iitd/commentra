<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define the structure for edges
type edge struct {
	s, g, c int
}

// Define the structure for the graph
type graph struct {
	vcnt, ecnt int
	e          [200010]edge //適宜変える // Define the array of edges
	id         [100010]int  //適宜変える // Define the array of indices
}

<<<<<<< HEAD
//辺の情報を個別に持つタイプ

=======
>>>>>>> 98c87cb78a (data updated)
// Define a function to sort edges
func esort(a, b interface{}) int {
	p := a.(*edge)
	q := b.(*edge)
	if p.s < q.s {
		return -1
	}
	if p.s > q.s {
		return 1
	}
	if p.g < q.g {
		return -1
	}
	return 1
}

// Define a function to read the graph
func readgraph() {
	//適宜変える
	var n int
	fmt.Scanf("%d\n", &n) // Read the number of vertices
	for i := 0; i < n-1; i++ { // Read each edge and store it in the graph structure
		var x, y, c int
		fmt.Scanf("%d%d%d\n", &x, &y, &c)
		g.e[2*i].s = x
		g.e[2*i].g = y
		g.e[2*i].c = c
		g.e[2*i+1].s = y
		g.e[2*i+1].g = x
		g.e[2*i+1].c = c
	}
	g.vcnt = n // Set the number of vertices
	g.ecnt = 2*n - 2 // Set the number of edges
	sort.Slice(g.e[:g.ecnt], func(i, j int) bool { return esort(&g.e[i], &g.e[j]) < 0 }) // Sort the edges

	var p int
	for i := 0; i < g.vcnt; i++ { // Populate the id array with the starting index of edges for each vertex
		for p < g.ecnt && g.e[p].s < i {
			p++
		}
		g.id[i] = p
	}
	g.id[g.vcnt] = g.ecnt //番兵 // Set the sentinel value for the id array
}

//木の直径を求める2回dfs
<<<<<<< HEAD

// Define a temporary array for DFS
var tyokkeitemp []int

// Define a function to perform DFS and update distances
func tyokkeidfs(s int) {
	for i := g.id[s]; i < g.id[s+1]; i++ {
		if tyokkeitemp[g.e[i].g] == 0 {
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
			tyokkeidfs(g.e[i].g)
		}
	}
}

// Define a function to find the diameter of the tree
func tyokkei() int {
	tyokkeitemp = make([]int, g.vcnt+10) // Allocate memory for the temporary array
	tyokkeitemp[0] = 1 // Start DFS from the root
	tyokkeidfs(0) // Perform DFS
	var M, Mi int // Initialize variables to find the maximum distance
=======
func tyokkei() int {
	tyokkeitemp := make([]int, g.vcnt+10) // Define a temporary array for DFS
	tyokkeitemp[0] = 1 // Start DFS from the root
	for i := 0; i < g.vcnt; i++ {
		for p := g.id[i]; p < g.id[i+1]; p++ {
			if tyokkeitemp[g.e[p].g] == 0 {
				tyokkeitemp[g.e[p].g] = tyokkeitemp[i] + g.e[p].c
				tyokkei()
			}
		}
	}
	var M, Mi int
>>>>>>> 98c87cb78a (data updated)
	for i := 0; i < g.vcnt; i++ { // Find the vertex with the maximum distance from the root
		if tyokkeitemp[i] > M {
			M = tyokkeitemp[i]
			Mi = i
		}
	}
	for i := 0; i < g.vcnt; i++ {
		tyokkeitemp[i] = 0
	}
	tyokkeitemp[Mi] = 1 // Start DFS from the farthest vertex found
<<<<<<< HEAD
	tyokkeidfs(Mi) // Perform DFS
	M = 0
	for i := 0; i < g.vcnt; i++ {
		M = max(M, tyokkeitemp[i]) // Find the maximum distance in the second DFS
	}
	return M - 1 // Return the diameter of the tree
}

func main() { // Define the main function
=======
	for i := 0; i < g.vcnt; i++ {
		if tyokkeitemp[i] == 0 {
			tyokkeitemp[i] = 1
			tyokkei()
		}
	}
	for i := 0; i < g.vcnt; i++ {
		M = max(M, tyokkeitemp[i])
	}
	return M - 1
}

func main() {
>>>>>>> 98c87cb78a (data updated)
	readgraph() // Read the graph
	fmt.Printf("%d\n", tyokkei()) // Print the diameter of the tree
}

