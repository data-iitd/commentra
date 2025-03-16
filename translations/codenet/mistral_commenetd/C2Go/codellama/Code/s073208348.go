
// This is a Go code for finding the diameter of a tree using Depth-First Search (DFS) algorithm.
//
// package main
// import "fmt"
// import "math"
// import "sort"
// import "strconv"
// import "strings"
// import "time"

// Define the structure for the edge and graph.
type E struct{s,g,c int} // An edge has source, destination, and cost.
type G struct{
	vcnt,ecnt int // Number of vertices and edges in the graph.
	e []E // Array to store edges.
	id []int // Array to store the index of each vertex in the sorted edge list.
}

// Comparison function for sort to sort edges based on their source vertex.
func esort(a,b interface{})int{
	p,q := a.(E),b.(E)
	if(p.s<q.s)return -1
	if(p.s>q.s)return  1
	if(p.g<q.g)return -1
	return 1
}

// Initialize the graph structure.
var g G

// Read the graph from the standard input.
func readgraph(){
	// Read the number of vertices.
	var n int
	fmt.Scan(&n)
	// Allocate memory for the vertices and edges.
	g.vcnt = n
	g.ecnt = 2*n-2
	// Allocate memory for the edge array and sort it.
	g.e = make([]E,g.ecnt+10)
	rep(i,0,n-1){
		var x,y,c int
		fmt.Scan(&x,&y,&c)
		// Add an edge from x to y and y to x with the given cost.
		g.e[i].s = x
		g.e[i].g = y
		g.e[i].c = c
		g.e[i+g.ecnt].s = y
		g.e[i+g.ecnt].g = x
		g.e[i+g.ecnt].c = c
	}
	// Set the number of edges.
	g.ecnt *= 2
	// Sort the edges using sort.
	sort.Slice(g.e,esort)
	// Initialize the id array.
	p := 0
	rep(i,0,g.vcnt){
		// Find the index of the current vertex in the sorted edge list.
		for p<g.ecnt&&g.e[p].s<i{p++}
		g.id[i] = p
	}
	// Set the last index as a sentinel.
	g.id[g.vcnt] = g.ecnt
}

// Function to find the diameter of the tree using DFS algorithm.
// *tyokkeitemp is an array to store the depth of each vertex from the root.
var tyokkeitemp []int
func tyokkeidfs(s int){
	// Iterate through the edges connected to the current vertex.
	for i:=g.id[s];i<g.id[s+1];i++{
		// If the destination vertex has not been visited yet, recursively call tyokkeidfs.
		if(tyokkeitemp[g.e[i].g]==0){
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
			tyokkeidfs(g.e[i].g)
		}
	}
}
func tyokkei()int{
	// Allocate memory for tyokkeitemp array.
	tyokkeitemp = make([]int,g.vcnt+10)
	// Initialize the root vertex depth to 1.
	tyokkeitemp[0] = 1
	// Perform DFS from the root vertex.
	tyokkeidfs(0)
	// Find the maximum depth.
	M,Mi := 0,0
	rep(i,0,g.vcnt){
		// If the current vertex depth is greater than the maximum depth, update it.
		if(tyokkeitemp[i]>M){
			M = tyokkeitemp[i]
			Mi = i
		}
	}
	// Free the memory allocated for tyokkeitemp.
	tyokkeitemp = nil
	// Return the diameter which is the maximum depth minus 1.
	return M-1
}
// Main function to read the graph and print the diameter.
func main(){
	// Read the graph.
	readgraph()
	// Call the tyokkei function to find the diameter.
	fmt.Println(tyokkei())
	// Free the memory allocated for the edge array.
	g.e = nil
}

