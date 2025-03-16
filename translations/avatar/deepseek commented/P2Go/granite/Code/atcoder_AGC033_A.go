

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
	reader := bufio.NewReader(os.Stdin)
	h, w := readTwoNums(reader)

	// Initialize the grid with 0 for '.' and inf for '#'
	graph := make([][]int, h)
	for i := 0; i < h; i++ {
		graph[i] = make([]int, w)
		for j := 0; j < w; j++ {
			if s, _ := reader.ReadByte(); s == '#' {
				graph[i][j] = 1 << 30
			} else {
				graph[i][j] = 0
			}
		}
	}

	// Calculate the minimum distance to any '#' for each cell in the grid
	// Processing in the left to right direction
	for x := 0; x < w-1; x++ {
		for y := 0; y < h; y++ {
			graph[y][x+1] = min(graph[y][x+1], graph[y][x]+1)
		}
	}

	// Processing in the right to left direction
	for x := w - 1; x > 0; x-- {
		for y := 0; y < h; y++ {
			graph[y][x-1] = min(graph[y][x-1], graph[y][x]+1)
		}
	}

	// Processing in the top to bottom direction
	for y := 0; y < h-1; y++ {
		for x := 0; x < w; x++ {
			graph[y+1][x] = min(graph[y+1][x], graph[y][x]+1)
		}
	}

	// Processing in the bottom to top direction
	for y := h - 1; y > 0; y-- {
		for x := 0; x < w; x++ {
			graph[y-1][x] = min(graph[y-1][x], graph[y][x]+1)
		}
	}

	// Print the maximum value in the grid, which represents the maximum distance to the nearest '#'
	max := 0
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			max = max(max, graph[i][j])
		}
	}
	fmt.Println(max)
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func min(a, b int) int {
	return a + b - max(a, b)
}