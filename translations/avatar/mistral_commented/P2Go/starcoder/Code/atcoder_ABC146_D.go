#######
// Code
#######

// Import necessary libraries
import (
	"container/list"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to perform Breadth First Search (BFS)
func bfs(v int, N int, G []list.List, E map[int]int) int {
	// Initialize visited array and queue
	visited := make([]int, N)
	queue := list.New()

	// Initialize variables for coloring nodes
	K := -1
	node2color := make([]int, N)

	// Add starting node to the queue and mark it as visited
	queue.PushBack(v)
	visited[v] = 1

	// BFS algorithm
	for queue.Len() > 0 {
		// Dequeue the next node from the queue
		q := queue.Remove(queue.Front()).(int)

		// Initialize color for the current node
		color := 0

		// Traverse through all neighbors of the current node
		for e := G[q].Front(); e!= nil; e = e.Next() {
			// Skip if the neighbor is already visited
			nex := e.Value.(int)
			if visited[nex] {
				continue
			}

			// Mark the neighbor as visited and assign it a color
			visited[nex] = 1
			color += 1

			// If the color of the current node is same as its neighbor, assign a new color to the neighbor
			if color == node2color[q] {
				color += 1
			}

			// Update node2color and E dictionary with the new color
			node2color[nex] = color
			E[min(q, nex)*N+max(q, nex)] = color

			// Add the neighbor to the queue
			queue.PushBack(nex)

		}

		// Update the maximum color found so far
		K = max(K, color)

	}

	// Return the maximum color
	return K

// Main function to read input and call bfs function
func main() {
	// Read number of nodes from the input
	N, _ := strconv.Atoi(strings.TrimSpace(os.Args[1]))

	// Initialize graph as a list of deques and empty dictionary for edges
	G := make([]list.List, N)
	E := make(map[int]int)

	// Read edges from the input and add them to the graph
	for i := 0; i < N-1; i++ {
		a, b := strings.Split(strings.TrimSpace(os.Args[i+2]), " ")
		a, b = int(a)-1, int(b)-1
		G[a].PushBack(b)
		G[b].PushBack(a)
		E[min(a, b)*N+max(a, b)] = 0

	}

	// Call bfs function and print the result
	K := bfs(0, N, G, E)
	fmt.Println(K)

	// Print colors of all edges
	for _, value := range E {
		fmt.Println(value)
	}

}

// Call the main function
main()

