package main

import (
	"bufio"
	"fmt"
	"os"
)

type Point struct {
	name   int
	friends map[*Point]int
}

func (p *Point) becomeFriend(friend *Point, length int) {
	p.friends[friend] = length
}

var colors []int

func dfs(p *Point, length int) {
	alreadyKnown := colors[p.name] != -1
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n := toInt(scanner.Bytes())
	m := n - 1
	colors = make([]int, n)
	for i := 0; i < n; i++ {
		colors[i] = -1
	}
	points := make([]*Point, n)
	for i := 0; i < n; i++ {
		points[i] = &Point{i, make(map[*Point]int)}
	}
	for i := 0; i < m; i++ {
		scanner.Scan()
		me := toInt(scanner.Bytes()) - 1
		scanner.Scan()
		you := toInt(scanner.Bytes()) - 1
		scanner.Scan()
		length := toInt(scanner.Bytes())
		points[me].becomeFriend(points[you], length)
		points[you].becomeFriend(points[me], length)
	}
	dfs(points[0], 0)
	for _, c := range colors {
		fmt.Println(c)
	}
}

func toInt(buf []byte) int {
	i := 0
	for _, b := range buf {
		i = i*10 + int(b-'0')
	}
	return i
}

