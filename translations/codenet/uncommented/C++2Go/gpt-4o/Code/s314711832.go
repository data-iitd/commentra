package main

import (
	"fmt"
	"math"
)

const (
	INF = 1000000001
	N   = 100000
)

type edge struct {
	source int
	target int
	weight int
}

var edges []edge
var distances [N]int
var prevDistances [N]int

func main() {
	var V, E, r int
	fmt.Scan(&V, &E, &r)

	for i := 0; i < E; i++ {
		var source, target, distance int
		fmt.Scan(&source, &target, &distance)
		newEdge := edge{source: source, target: target, weight: distance}
		edges = append(edges, newEdge)
	}

	// Initialize distances array
	for i := 0; i < N; i++ {
		distances[i] = INF // max value
	}

	distances[r] = 0

	for i := 1; i < V; i++ {
		copy(prevDistances[:], distances[:])

		for _, e := range edges {
			if distances[e.source]+e.weight < distances[e.target] {
				distances[e.target] = distances[e.source] + e.weight
			}
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
		if distances[i] == INF {
			fmt.Println("INF")
		} else {
			fmt.Println(distances[i])
		}
	}
}

// <END-OF-CODE>
