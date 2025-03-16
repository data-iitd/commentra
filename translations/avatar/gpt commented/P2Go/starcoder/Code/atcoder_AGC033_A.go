package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the height (h) and width (w) of the graph from input
	h, w := readInput()

	// Initialize the graph:
	// Replace '#' with 0 (indicating an obstacle) and other characters with infinity (indicating unvisited cells)
	graph := make([][]int, h)
	for i := range graph {
		graph[i] = make([]int, w)
		for j := range graph[i] {
			if string(os.Stdin.Next()) == "#" {
				graph[i][j] = 0
			} else {
				graph[i][j] = 1000000000
			}
		}
	}

	// Update the graph by calculating the minimum distance from the left side
	for x := 0; x < w-1; x++ {
		// For each column, update the distance from the previous column
		for y := 0; y < h; y++ {
			graph[y][x+1] = min(graph[y][x]+1, graph[y][x+1])
		}
	}

	// Update the graph by calculating the minimum distance from the right side
	for x := w-1; x > 0; x-- {
		// For each column, update the distance from the next column
		for y := 0; y < h; y++ {
			graph[y][x-1] = min(graph[y][x]+1, graph[y][x-1])
		}
	}

	// Update the graph by calculating the minimum distance from the top side
	for y := 0; y < h-1; y++ {
		// For each row, update the distance from the previous row
		for x := 0; x < w; x++ {
			graph[y+1][x] = min(graph[y][x]+1, graph[y+1][x])
		}
	}

	// Update the graph by calculating the minimum distance from the bottom side
	for y := h-1; y > 0; y-- {
		// For each row, update the distance from the next row
		for x := 0; x < w; x++ {
			graph[y-1][x] = min(graph[y][x]+1, graph[y-1][x])
		}
	}

	// Print the maximum distance found in the graph, which represents the farthest distance from an obstacle
	fmt.Println(max(graph))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func readInput() (int, int) {
	reader := bufio.NewReader(os.Stdin)
	h, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	w, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	return h, w
}

