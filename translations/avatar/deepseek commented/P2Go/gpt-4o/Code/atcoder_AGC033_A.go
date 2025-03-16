package main

import (
	"fmt"
	"math"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	// Initialize the grid with 0 for '#' and inf for '.'
	graph := make([][]float64, h)
	for i := range graph {
		graph[i] = make([]float64, w)
		for j := range graph[i] {
			var cell byte
			fmt.Scan(&cell)
			if cell == '#' {
				graph[i][j] = 0
			} else {
				graph[i][j] = math.Inf(1)
			}
		}
	}

	// Processing in the left to right direction
	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			graph[y][x+1] = math.Min(graph[y][x]+1, graph[y][x+1])
		}
	}

	// Processing in the right to left direction
	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x-1] = math.Min(graph[y][x]+1, graph[y][x-1])
		}
	}

	// Processing in the top to bottom direction
	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			graph[y+1][x] = math.Min(graph[y][x]+1, graph[y+1][x])
		}
	}

	// Processing in the bottom to top direction
	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			graph[y-1][x] = math.Min(graph[y][x]+1, graph[y-1][x])
		}
	}

	// Find the maximum value in the grid
	maxDistance := 0.0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > maxDistance {
				maxDistance = graph[y][x]
			}
		}
	}

	// Print the maximum value, which represents the maximum distance to the nearest '#'
	fmt.Println(int(maxDistance))
}

// <END-OF-CODE>
