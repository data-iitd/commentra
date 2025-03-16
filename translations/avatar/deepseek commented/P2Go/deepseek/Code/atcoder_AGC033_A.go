package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	dims := strings.Split(strings.TrimSpace(line), " ")
	h, _ := strconv.Atoi(dims[0])
	w, _ := strconv.Atoi(dims[1])

	// Initialize the grid with 0 for '.' and inf for '#'
	graph := make([][]int, h)
	for i := 0; i < h; i++ {
		line, _ = reader.ReadString('\n')
		row := []byte(strings.TrimSpace(line))
		graph[i] = make([]int, w)
		for j := 0; j < w; j++ {
			if row[j] == '#' {
				graph[i][j] = int(^uint(0) >> 1) // Max int value for infinity
			} else {
				graph[i][j] = 0
			}
		}
	}

	// Calculate the minimum distance to any '#' for each cell in the grid
	// Processing in the left to right direction
	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			if graph[y][x+1] > graph[y][x]+1 {
				graph[y][x+1] = graph[y][x] + 1
			}
		}
	}

	// Processing in the right to left direction
	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			if graph[y][x-1] > graph[y][x]+1 {
				graph[y][x-1] = graph[y][x] + 1
			}
		}
	}

	// Processing in the top to bottom direction
	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			if graph[y+1][x] > graph[y][x]+1 {
				graph[y+1][x] = graph[y][x] + 1
			}
		}
	}

	// Processing in the bottom to top direction
	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			if graph[y-1][x] > graph[y][x]+1 {
				graph[y-1][x] = graph[y][x] + 1
			}
		}
	}

	// Find the maximum value in the grid, which represents the maximum distance to the nearest '#'
	maxDist := 0
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > maxDist {
				maxDist = graph[y][x]
			}
		}
	}

	fmt.Println(maxDist)
}

