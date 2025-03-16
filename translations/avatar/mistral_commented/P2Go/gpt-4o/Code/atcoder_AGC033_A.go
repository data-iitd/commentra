package main

import (
	"fmt"
	"math"
)

func main() {
	// Taking input dimensions of the graph
	var h, w int
	fmt.Scan(&h, &w)

	// Initializing the graph as a 2D slice with initial values
	graph := make([][]float64, h)
	for i := range graph {
		graph[i] = make([]float64, w)
		for j := 0; j < w; j++ {
			var ch byte
			fmt.Scanf("%c", &ch)
			if ch == '#' {
				graph[i][j] = 0
			} else {
				graph[i][j] = math.Inf(1)
			}
		}
		// Consume the newline character after each row
		var discard string
		fmt.Scanln(&discard)
	}

	// Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			graph[y][x+1] = math.Min(graph[y][x]+1, graph[y][x+1])
		}
	}

	// Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x-1] = math.Min(graph[y][x]+1, graph[y][x-1])
		}
	}

	// Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			graph[y+1][x] = math.Min(graph[y][x]+1, graph[y+1][x])
		}
	}

	// Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			graph[y-1][x] = math.Min(graph[y][x]+1, graph[y-1][x])
		}
	}

	// Finding and printing the maximum shortest path distance in the graph
	maxDistance := math.Inf(-1)
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > maxDistance {
				maxDistance = graph[y][x]
			}
		}
	}
	fmt.Println(int(maxDistance))
}

// <END-OF-CODE>
