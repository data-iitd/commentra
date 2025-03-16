package main

import (
	"fmt"
	"math"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	// Initialize the graph
	graph := make([][]float64, h)
	for i := 0; i < h; i++ {
		graph[i] = make([]float64, w)
		var row string
		fmt.Scan(&row)
		for j, char := range row {
			if char == '#' {
				graph[i][j] = 0 // obstacle
			} else {
				graph[i][j] = math.Inf(1) // unvisited cells
			}
		}
	}

	// Update the graph by calculating the minimum distance from the left side
	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			graph[y][x+1] = math.Min(graph[y][x]+1, graph[y][x+1])
		}
	}

	// Update the graph by calculating the minimum distance from the right side
	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x-1] = math.Min(graph[y][x]+1, graph[y][x-1])
		}
	}

	// Update the graph by calculating the minimum distance from the top side
	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			graph[y+1][x] = math.Min(graph[y][x]+1, graph[y+1][x])
		}
	}

	// Update the graph by calculating the minimum distance from the bottom side
	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			graph[y-1][x] = math.Min(graph[y][x]+1, graph[y-1][x])
		}
	}

	// Find the maximum distance in the graph
	maxDistance := 0.0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > maxDistance {
				maxDistance = graph[y][x]
			}
		}
	}

	// Print the maximum distance found in the graph
	fmt.Println(int(maxDistance))
}

// <END-OF-CODE>
