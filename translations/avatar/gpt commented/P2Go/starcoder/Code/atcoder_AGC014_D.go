package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Read input from standard input
var reader = bufio.NewReader(os.Stdin)

// Read the number of nodes in the tree
func readNum() int {
	i, _ := strconv.Atoi(readLine())
	return i
}

// Read a line of input from standard input
func readLine() string {
	text, _ := reader.ReadString('\n')
	return text[:len(text)-1]
}

// Initialize adjacency list for the tree
var adj = make([][]int, 0)

// Read edges and build the adjacency list
func readEdges() {
	n := readNum()
	for i := 0; i < n-1; i++ {
		a, b := readNum(), readNum()
		adj = append(adj, []int{a, b})
		adj = append(adj, []int{b, a})
	}
}

// Initialize a queue for BFS and mark the starting node
var que = make([]int, 0)

// Array to keep track of visited nodes
var seen = make([]int, 0)

// Array to store parent of each node
var par = make([]int, 0)

// Array to count the number of children for each node
var child_num = make([]int, 0)

// Perform BFS to populate parent and child count information
func bfs() {
	que = append(que, 1)
	seen = append(seen, 1)
	par = append(par, 0)
	child_num = append(child_num, 0)
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		for _, u := range adj[v-1] {
			if seen[u-1] == 0 {
				seen[u-1] = 1
				par[u-1] = v
				child_num[v-1] += 1
				que = append(que, u)
			}
		}
	}
}

// Initialize a deque to process leaf nodes
var seq = make([]int, 0)

// Identify all leaf nodes (nodes with no children)
func findLeafNodes() {
	for i := 0; i < len(child_num); i++ {
		if child_num[i] == 0 {
			seq = append(seq, i+1)
		}
	}
}

// Process the leaf nodes in reverse order
func processLeafNodes() {
	for len(seq) > 0 {
		c := seq[len(seq)-1]
		seen[c-1] = 0
		if seen[par[c-1]-1] == 0 {
			fmt.Println("First")
			return
		}
		seen[par[c-1]-1] = 0
		child_num[par[par[c-1]-1]-1] -= 1
		if child_num[par[par[c-1]-1]-1] == 0 {
			seq = append(seq, par[par[c-1]-1])
		}
	}
	fmt.Println("Second")
}

func main() {
	readEdges()
	bfs()
	findLeafNodes()
	processLeafNodes()
}

