
package main

import (
	"fmt"
	"math"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)

	graph := make([][]int, h)
	for i := range graph {
		graph[i] = make([]int, w)
		for j := range graph[i] {
			var c byte
			fmt.Scanf("%c", &c)
			if c == '#' {
				graph[i][j] = math.MaxInt32
			} else {
				graph[i][j] = 0
			}
		}
	}

	// Processing in the left to right direction
	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			graph[y][x+1] = int(math.Min(float64(graph[y][x]+1), float64(graph[y][x+1])))
		}
	}

	// Processing in the right to left direction
	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x-1] = int(math.Min(float64(graph[y][x]+1), float64(graph[y][x-1])))
		}
	}

	// Processing in the top to bottom direction
	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			graph[y+1][x] = int(math.Min(float64(graph[y][x]+1), float64(graph[y+1][x])))
		}
	}

	// Processing in the bottom to top direction
	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			graph[y-1][x] = int(math.Min(float64(graph[y][x]+1), float64(graph[y-1][x])))
		}
	}

	// Print the maximum value in the grid, which represents the maximum distance to the nearest '#'
	max := 0
	for i := range graph {
		for j := range graph[i] {
			if graph[i][j] > max {
				max = graph[i][j]
			}
		}
	}
	fmt.Println(max)
}

