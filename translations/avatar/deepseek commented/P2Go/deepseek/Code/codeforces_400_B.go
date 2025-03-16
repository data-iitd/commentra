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
	line1, _ := reader.ReadString('\n')
	line1 = strings.TrimSpace(line1)
	parts := strings.Split(line1, " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	var grid []string
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		grid = append(grid, line)
	}

	c := make(map[int]bool)
	for _, row := range grid {
		sIndex := strings.Index(row, "S")
		gIndex := strings.Index(row, "G")
		if sIndex != -1 && gIndex != -1 {
			diff := sIndex - gIndex
			if diff < 0 {
				c[diff] = true
			}
		}
	}

	if len(c) == 0 {
		fmt.Println(-1)
	} else {
		fmt.Println(len(c))
	}
}
