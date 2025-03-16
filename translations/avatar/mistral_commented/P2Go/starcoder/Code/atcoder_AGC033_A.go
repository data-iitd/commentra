package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Reading the dimensions of the graph
	h, w := readInput(reader)

	// Initializing the graph as a 2D NumPy array with initial values
	graph := make([][]int, h)
	for i := range graph {
		graph[i] = make([]int, w)
	}

	// Reading the graph
	for i := 0; i < h; i++ {
		line, _ := reader.ReadString('\n')
		for j := 0; j < w; j++ {
			graph[i][j] = 0 if line[j] == '#' else 1000000000
		}
	}

	// Performing Dijkstra's shortest path algorithm in the horizontal direction from left to right
	for x := 0; x < w - 1; x++ {
		for i := 0; i < h; i++ {
			graph[i][x] = min(graph[i][x] + 1, graph[i][x + 1])
		}
	}

	// Performing Dijkstra's shortest path algorithm in the horizontal direction from right to left
	for x := w - 1; x > 0; x-- {
		for i := 0; i < h; i++ {
			graph[i][x] = min(graph[i][x] + 1, graph[i][x - 1])
		}
	}

	// Performing Dijkstra's shortest path algorithm in the vertical direction from top to bottom
	for y := 0; y < h - 1; y++ {
		for i := 0; i < w; i++ {
			graph[y][i] = min(graph[y][i] + 1, graph[y + 1][i])
		}
	}

	// Performing Dijkstra's shortest path algorithm in the vertical direction from bottom to top
	for y := h - 1; y > 0; y-- {
		for i := 0; i < w; i++ {
			graph[y][i] = min(graph[y][i] + 1, graph[y - 1][i])
		}
	}

	// Finding and printing the maximum shortest path distance in the graph
	fmt.Println(max(graph))
}

// Reads input from stdin
func readInput(reader *bufio.Reader) (int, int) {
	// Reading the dimensions of the graph
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	h, w := strings.Split(line, " "), 0
	h, w = len(h), len(h[0])

	return h, w
}

// Returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Returns the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

