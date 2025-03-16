<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

type edge struct {
	source int
	target int
	weight int
}

func main() {
	var V, E, r int
	fmt.Scanf("%d %d %d", &V, &E, &r)

	var edges []edge
	for i := 0; i < E; i++ {
		var source, target, distance int
		fmt.Scanf("%d %d %d", &source, &target, &distance)
		edges = append(edges, edge{source, target, distance})
	}

	var distances [100000]int
	for i := 0; i < V; i++ {
		distances[i] = math.MaxInt32
	}
	distances[r] = 0

	for i := 1; i < V; i++ {
		var prev_distances [100000]int
		for j := 0; j < V; j++ {
			prev_distances[j] = distances[j]
		}

		for _, edge := range edges {
			distances[edge.target] = int(math.Min(float64(distances[edge.source]+edge.weight), float64(distances[edge.target])))
		}

		same := true
		for j := 0; j < V; j++ {
			if distances[j]!= prev_distances[j] {
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

