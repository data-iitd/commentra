
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Edge struct {
	source int
	target int
	weight int
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	var V, E, r int
	fmt.Fscanf(reader, "%d %d %d\n", &V, &E, &r)

	edges := make([]Edge, E)
	for i := 0; i < E; i++ {
		var source, target, weight int
		fmt.Fscanf(reader, "%d %d %d\n", &source, &target, &weight)
		edges[i] = Edge{source, target, weight}
	}

	distances := make([]int, V)
	for i := 0; i < V; i++ {
		distances[i] = 1000000001 // Set all distances to a maximum value (infinity)
	}

	distances[r] = 0 // Set the distance to the source vertex to 0

	for i := 1; i < V; i++ {
		prevDistances := make([]int, V)
		copy(prevDistances, distances)

		for _, edge := range edges {
			if distances[edge.source]+edge.weight < distances[edge.target] {
				distances[edge.target] = distances[edge.source] + edge.weight
			}
		}

		same := true
		for j := 0; j < V; j++ {
			if distances[j]!= prevDistances[j] {
				same = false
				break
			}
		}

		if same {
			break
		}
	}

	for i := 0; i < V; i++ {
		if distances[i] == 1000000001 {
			fmt.Println("INF") // Print "INF" if the vertex is unreachable
		} else {
			fmt.Println(distances[i]) // Print the shortest distance
		}
	}
}
