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
			fmt.Scan(&graph[i][j])
			if graph[i][j] == '#' {
				graph[i][j] = 0
			} else {
				graph[i][j] = math.MaxInt32
			}
		}
	}
	for x := 1; x < w; x++ {
		for y := 0; y < h; y++ {
			graph[y][x] = int(math.Min(float64(graph[y][x-1]), float64(graph[y][x]))) + 1
		}
	}
	for x := w - 2; x >= 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x] = int(math.Min(float64(graph[y][x+1]), float64(graph[y][x]))) + 1
		}
	}
	for y := 1; y < h; y++ {
		for x := 0; x < w; x++ {
			graph[y][x] = int(math.Min(float64(graph[y-1][x]), float64(graph[y][x]))) + 1
		}
	}
	for y := h - 2; y >= 0; y-- {
		for x := 0; x < w; x++ {
			graph[y][x] = int(math.Min(float64(graph[y+1][x]), float64(graph[y][x]))) + 1
		}
	}
	var max int
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > max {
				max = graph[y][x]
			}
		}
	}
	fmt.Println(max)
}

