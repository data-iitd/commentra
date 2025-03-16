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

	graph := make([][]int, h)
	for i := 0; i < h; i++ {
		line, _ := reader.ReadString('\n')
		row := []byte(strings.TrimSpace(line))
		graph[i] = make([]int, w)
		for j := 0; j < w; j++ {
			if row[j] == '#' {
				graph[i][j] = 0
			} else {
				graph[i][j] = int(^uint(0) >> 1) // math.MaxInt64
			}
		}
	}

	// Horizontal pathfinding from left to right
	for y := 0; y < h; y++ {
		for x := 0; x < w-1; x++ {
			if graph[y][x+1] > graph[y][x]+1 {
				graph[y][x+1] = graph[y][x] + 1
			}
		}
	}

	// Horizontal pathfinding from right to left
	for y := 0; y < h; y++ {
		for x := w - 1; x > 0; x-- {
			if graph[y][x-1] > graph[y][x]+1 {
				graph[y][x-1] = graph[y][x] + 1
			}
		}
	}

	// Vertical pathfinding from top to bottom
	for x := 0; x < w; x++ {
		for y := 0; y < h-1; y++ {
			if graph[y+1][x] > graph[y][x]+1 {
				graph[y+1][x] = graph[y][x] + 1
			}
		}
	}

	// Vertical pathfinding from bottom to top
	for x := 0; x < w; x++ {
		for y := h - 1; y > 0; y-- {
			if graph[y-1][x] > graph[y][x]+1 {
				graph[y-1][x] = graph[y][x] + 1
			}
		}
	}

	// Find the maximum shortest path distance
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
