package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var V, E, r int
	fmt.Fscan(reader, &V, &E, &r)

	edges := []edge{}
	distances := make([]int, N)
	prevDistances := make([]int, N)

	for i := 0; i < N; i++ {
		distances[i] = INF
	}

	distances[r] = 0

	for i := 0; i < E; i++ {
		var source, target, distance int
		fmt.Fscan(reader, &source, &target, &distance)
		newEdge := edge{source, target, distance}
		edges = append(edges, newEdge)
	}

	for i := 1; i < V; i++ {
		copy(prevDistances, distances)

		for _, edge := range edges {
			if distances[edge.source]+edge.weight < distances[edge.target] {
				distances[edge.target] = distances[edge.source] + edge.weight
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
			fmt.Fprintln(writer, "INF")
		} else {
			fmt.Fprintln(writer, distances[i])
		}
	}
