
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the dimensions of the grid
	h, w := readDimensions()

	// Initialize the grid with 0 for '.' and inf for '#'
	graph := make([][]int, h)
	for i := range graph {
		graph[i] = make([]int, w)
	}

	// Calculate the minimum distance to any '#' for each cell in the grid
	// Processing in the left to right direction
	for x := 0; x < w - 1; x++ {
		for y := 0; y < h; y++ {
			graph[y][x + 1] = min(graph[y][x] + 1, graph[y][x + 1])
		}
	}

	// Processing in the right to left direction
	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x - 1] = min(graph[y][x] + 1, graph[y][x - 1])
		}
	}

	// Processing in the top to bottom direction
	for y := 0; y < h - 1; y++ {
		for x := 0; x < w; x++ {
			graph[y + 1][x] = min(graph[y][x] + 1, graph[y + 1][x])
		}
	}

	// Processing in the bottom to top direction
	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			graph[y - 1][x] = min(graph[y][x] + 1, graph[y - 1][x])
		}
	}

	// Print the maximum value in the grid, which represents the maximum distance to the nearest '#'
	fmt.Println(max(graph))
}

func readDimensions() (int, int) {
	// Read the dimensions of the grid
	h, w := strings.Split(readLine(), " "), strings.Split(readLine(), " ")
	return atoi(h[0]), atoi(w[0])
}

func atoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a []int) int {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func readLine() string {
	stdin := bufio.NewReader(os.Stdin)
	line, _ := stdin.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

