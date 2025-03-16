
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Point represents a point in the graph
type Point struct {
	name   int
	friends map[int]int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	m := n - 1
	colors := make([]int, n)
	points := make([]Point, n)

	for i := 0; i < n; i++ {
		points[i] = Point{i, make(map[int]int)}
	}

	for m > 0 {
		me, _ := strconv.Atoi(readLine(reader))
		you, _ := strconv.Atoi(readLine(reader))
		length, _ := strconv.Atoi(readLine(reader))
		points[me-1].becomeFriend(points[you-1], length)
		points[you-1].becomeFriend(points[me-1], length)
		m--
	}

	dfs(points[0], 0)

	for _, c := range colors {
		fmt.Println(c)
	}
}

func dfs(p Point, length int) {
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

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func (p *Point) becomeFriend(friend Point, length int) {
	p.friends[friend.name] = length
}

