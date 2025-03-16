
package main

import (
	"fmt"
	"math"
)

func main() {
	var V, E, r int
	fmt.Scan(&V, &E, &r)

	edges := make([]struct {
		source, target, weight int
	}, E)

	for i := 0; i < E; i++ {
		fmt.Scan(&edges[i].source, &edges[i].target, &edges[i].weight)
	}

	distances := make([]int, V)
	for i := 0; i < V; i++ {
		distances[i] = math.MaxInt32
	}
	distances[r] = 0

	for i := 1; i < V; i++ {
		for j := 0; j < V; j++ {
			prevDistances[j] = distances[j]
		}

		for _, edge := range edges {
			distances[edge.target] = int(math.Min(float64(distances[edge.source]+edge.weight), float64(distances[edge.target])))
		}

		same := true
		for j := 0; j < V; j++ {
			if distances[j] != prevDistances[j] {
				same = false
				break
			}
		}

		if same {
			break
		}
	}

	for i := 0; i < V; i++ {
		if distances[i] == math.MaxInt32 {
			fmt.Println("INF")
		} else {
			fmt.Println(distances[i])
		}
	}
}

