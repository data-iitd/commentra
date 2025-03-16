package main

import (
	"bufio"
	"fmt"
	"math"
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

	graph := make([][]float64, h)
	for i := 0; i < h; i++ {
		line, _ := reader.ReadString('\n')
		row := []float64{}
		for _, char := range line {
			if char == '#' {
				row = append(row, float64(0))
			} else {
				row = append(row, math.Inf(0))
			}
		}
		graph[i] = row
	}

	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			graph[y][x+1] = math.Min(graph[y][x]+1, graph[y][x+1])
		}
	}

	for x := w - 2; x >= 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x] = math.Min(graph[y][x+1]+1, graph[y][x])
		}
	}

	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			graph[y+1][x] = math.Min(graph[y][x]+1, graph[y+1][x])
		}
	}

	for y := h - 2; y >= 0; y-- {
		for x := 0; x < w; x++ {
			graph[y][x] = math.Min(graph[y+1][x]+1, graph[y][x])
		}
	}

	maxVal := float64(0)
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if graph[y][x] > maxVal {
				maxVal = graph[y][x]
			}
		}
	}

	fmt.Println(int(maxVal))
}
