

package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
)

type Graph struct {
 adjacencyList map[int][]int
}

func NewGraph(numNodes int) *Graph {
 return &Graph{
 adjacencyList: make(map[int][]int),
 }
}

func (g *Graph) AddEdge(node1, node2 int) {
 g.adjacencyList[node1] = append(g.adjacencyList[node1], node2)
 g.adjacencyList[node2] = append(g.adjacencyList[node2], node1)
}

func (g *Graph) DFS(node, parent int, seen []bool, cycle *int, path *int) {
 seen[node] = true
 *path++
 for _, neighbor := range g.adjacencyList[node] {
 if neighbor!= parent {
 *cycle++
 if seen[neighbor] {
 *cycle = 1
 } else {
 g.DFS(neighbor, node, seen, cycle, path)
 }
 }
 }
}

func main() {
 reader := bufio.NewReader(os.Stdin)
 fmt.Println("Enter the number of nodes in the graph:")
 numNodes, _ := reader.ReadString('\n')
 numNodes, _ = strconv.Atoi(strings.TrimSpace(numNodes))
 fmt.Println("Enter the number of edges in the graph:")
 numEdges, _ := reader.ReadString('\n')
 numEdges, _ = strconv.Atoi(strings.TrimSpace(numEdges))
 graph := NewGraph(numNodes)
 for i := 0; i < numEdges; i++ {
 fmt.Println("Enter the nodes connected by an edge:")
 edge, _ := reader.ReadString('\n')
 edge = strings.TrimSpace(edge)
 edgeParts := strings.Split(edge, " ")
 node1, _ := strconv.Atoi(edgeParts[0])
 node2, _ := strconv.Atoi(edgeParts[1])
 graph.AddEdge(node1, node2)
 }
 seen := make([]bool, numNodes+1)
 cycle := 0
 path := 0
 toRemove := 0
 for i := 1; i <= numNodes; i++ {
 if!seen[i] {
 graph.DFS(i, 0, seen, &cycle, &path)
 if cycle == 1 {
 if path%2 == 1 {
 toRemove++
 }
 }
 }
 }
 if (numNodes - toRemove) % 2 == 1 {
 toRemove++
 }
 fmt.Println("Number of nodes to remove:", toRemove)
}

