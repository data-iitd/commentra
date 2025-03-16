package main

import (
	"fmt"
	"math"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	graph := make([][]float64, h)
	for i := 0; i < h; i++ {
		graph[i] = make([]float64, w)
		var row string
		fmt.Scan(&row)
		for j, ch := range row {
			if ch == '#' {
				graph[i][j] = 0
			} else {
				graph[i][j] = math.Inf(1)
			}
		}
	}

	// Update graph from left to right
	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			graph[y][x+1] = math.Min(graph[y][x]+1, graph[y][x+1])
		}
	}

	// Update graph from right to left
	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x-1] = math.Min(graph[y][x]+1, graph[y][x-1])
		}
	}

	// Update graph from top to bottom
	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			graph[y+1][x] = math.Min(graph[y][x]+1, graph[y+1][x])
		}
	}

	// Update graph from bottom to top
	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			graph[y-1][x] = math.Min(graph[y][x]+1, graph[y-1][x])
		}
	}

	// Find the maximum value in the graph
	maxValue := math.Inf(-1)
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > maxValue {
				maxValue = graph[y][x]
			}
		}
	}

	fmt.Println(int(maxValue))
}

// <END-OF-CODE>
