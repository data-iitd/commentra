
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var colors []int

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	m := n - 1
	colors = make([]int, n)
	for i := 0; i < n; i++ {
		colors[i] = -1
	}
	points := make([]*Point, n)
	for i := 0; i < n; i++ {
		points[i] = &Point{i}
	}
	for m > 0 {
		me, _ := strconv.Atoi(read(reader))
		you, _ := strconv.Atoi(read(reader))
		length, _ := strconv.Atoi(read(reader))
		points[me-1].becomeFriend(points[you-1], length)
		points[you-1].becomeFriend(points[me-1], length)
		m--
	}
	dfs(points[0], 0)
	for _, c := range colors {
		fmt.Println(c)
	}
}

func dfs(p *Point, length int) {
	alreadyKnown := colors[p.name]!= -1
	if alreadyKnown {
		return
	}
	if length%2 == 0 {
		colors[p.name] = 0
	} else {
		colors[p.name] = 1
	}
	for friend, length2 := range p.friends {
		dfs(friend, length+length2)
	}
}

type Point struct {
	name   int
	friends map[*Point]int
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return strings.TrimSpace(string(str))
}

