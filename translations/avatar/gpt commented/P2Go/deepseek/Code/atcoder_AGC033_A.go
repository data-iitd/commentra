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
	parts := strings.Split(strings.TrimSpace(line), " ")
	h, _ := strconv.Atoi(parts[0])
	w, _ := strconv.Atoi(parts[1])

	graph := make([][]int, h)
	for i := 0; i < h; i++ {
		line, _ := reader.ReadString('\n')
		row := []int{}
		for _, char := range line {
			if char == '#' {
				row = append(row, 0)
			} else {
				row = append(row, int(1e9))
			}
		}
		graph[i] = row
	}

	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			if graph[y][x+1] > graph[y][x]+1 {
				graph[y][x+1] = graph[y][x] + 1
			}
		}
	}

	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			if graph[y][x-1] > graph[y][x]+1 {
				graph[y][x-1] = graph[y][x] + 1
			}
		}
	}

	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			if graph[y+1][x] > graph[y][x]+1 {
				graph[y+1][x] = graph[y][x] + 1
			}
		}
	}

	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			if graph[y-1][x] > graph[y][x]+1 {
				graph[y-1][x] = graph[y][x] + 1
			}
		}
	}

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
