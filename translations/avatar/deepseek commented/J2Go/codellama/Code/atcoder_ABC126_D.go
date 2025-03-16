package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	var m int
	scanner.Scan()
	m, _ = strconv.Atoi(scanner.Text())
	colors := make([]int, n)
	for i := 0; i < n; i++ {
		colors[i] = -1
	}
	points := make([]Point, n)
	for i := 0; i < n; i++ {
		points[i] = Point{i, make(map[Point]int)}
	}
	for i := 0; i < m; i++ {
		var me int
		scanner.Scan()
		me, _ = strconv.Atoi(scanner.Text())
		var you int
		scanner.Scan()
		you, _ = strconv.Atoi(scanner.Text())
		var length int
		scanner.Scan()
		length, _ = strconv.Atoi(scanner.Text())
		points[me-1].becomeFriend(points[you-1], length)
		points[you-1].becomeFriend(points[me-1], length)
	}
	dfs(points[0], 0)
	for _, c := range colors {
		fmt.Println(c)
	}
}

type Point struct {
	name   int
	friends map[Point]int
}

func (p *Point) becomeFriend(p2 Point, length int) {
	p.friends[p2] = length
}

func dfs(p Point, length int) {
	alreadyKnown := colors[p.name] != -1
	if alreadyKnown {
		return
	}
	if length%2 == 0 {
		colors[p.name] = 0
	} else {
		colors[p.name] = 1
	}
	for p2, length2 := range p.friends {
		dfs(p2, length+length2)
	}
}

