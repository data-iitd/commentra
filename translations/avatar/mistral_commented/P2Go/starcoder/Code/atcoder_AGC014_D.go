
// Import necessary modules
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input
func input() string {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to convert string to integer
func strToInt(str string) int {
	val, _ := strconv.Atoi(str)
	return val
}

// Define number of vertices in the graph
var N int

// Initialize adjacency list with empty lists for each vertex
var adj [100001] []int

// Read edges and add them to the adjacency list
func readEdges() {
	for i := 0; i < N - 1; i++ {
		a, b := strToInt(input()), strToInt(input())
		// Add edge between vertices a and b in both directions
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}
}

// Initialize empty deque for BFS traversal
var que []int

// Mark starting vertex as visited and add it to the queue
func bfs(v int) {
	que = append(que, v)
	for len(que) > 0 {
		v = que[0]
		que = que[1:]
		// Iterate through neighbors of the current vertex
		for _, u := range adj[v] {
			// If neighbor is not yet visited, mark it as visited, update parent and child count
			if u == 0 {
				continue
			}
			if u == 1 {
				fmt.Println("First")
				return
			}
			que = append(que, u)
	}
}

// Initialize empty deque for storing vertices in topological order
var seq []int

// Find vertices with no incoming edges and add them to the sequence
func topoSort() {
	for i := 1; i <= N; i++ {
		// If vertex has no incoming edges, add it to the sequence
		if len(adj[i]) == 0 {
			seq = append(seq, i)
	}
}

// Topological sort using the sequence of vertices with no incoming edges
func topoSort2() {
	for len(seq) > 0 {
		c := seq[0]
		seq = seq[1:]
		// If parent of the current vertex is not yet processed, print "First" and exit
		if c == 1 {
			fmt.Println("First")
			return
		}
		// Mark parent as not visited and update child count of its parent
		adj[par[c]] = adj[par[c]][:len(adj[par[c]]) - 1]
		// If the parent of the parent has no children, add it to the sequence
		if len(adj[par[par[c]]]) == 0 {
			seq = append(seq, par[par[c]])
	}
}

// Main function
func main() {
	N = strToInt(input())
	readEdges()
	bfs(1)
	topoSort()
	topoSort2()
	fmt.Println("Second")
}

