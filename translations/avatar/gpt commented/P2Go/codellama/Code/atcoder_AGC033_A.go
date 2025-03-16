
package main

import (
	"fmt"
	"math"
)

func main() {
	// Read the height (h) and width (w) of the graph from input
	var h, w int
	fmt.Scan(&h, &w)

	// Initialize the graph:
	// Replace '#' with 0 (indicating an obstacle) and other characters with infinity (indicating unvisited cells)
	graph := make([][]float64, h)
	for i := range graph {
		graph[i] = make([]float64, w)
		for j := range graph[i] {
			if string(i) == "#" {
				graph[i][j] = 0
			} else {
				graph[i][j] = math.Inf(1)
			}
		}
	}

	// Update the graph by calculating the minimum distance from the left side
	for x := 0; x < w-1; x++ {
		// For each column, update the distance from the previous column
		for y := 0; y < h; y++ {
			graph[y][x+1] = math.Min(graph[y][x]+1, graph[y][x+1])
		}
	}

	// Update the graph by calculating the minimum distance from the right side
	for x := w - 1; x > 0; x-- {
		// For each column, update the distance from the next column
		for y := 0; y < h; y++ {
			graph[y][x-1] = math.Min(graph[y][x]+1, graph[y][x-1])
		}
	}

	// Update the graph by calculating the minimum distance from the top side
	for y := 0; y < h-1; y++ {
		// For each row, update the distance from the previous row
		for x := 0; x < w; x++ {
			graph[y+1][x] = math.Min(graph[y][x]+1, graph[y+1][x])
		}
	}

	// Update the graph by calculating the minimum distance from the bottom side
	for y := h - 1; y > 0; y-- {
		// For each row, update the distance from the next row
		for x := 0; x < w; x++ {
			graph[y-1][x] = math.Min(graph[y][x]+1, graph[y-1][x])
		}
	}

	// Print the maximum distance found in the graph, which represents the farthest distance from an obstacle
	max := math.Inf(-1)
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > max {
				max = graph[y][x]
			}
		}
	}
	fmt.Println(int(max))
}

