package main

import (
	"bufio"
	"fmt"
	"os"
)

var colors []int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n := toInt(scanner.Text())
	m := n - 1
	colors = make([]int, n)
	for i := 0; i < n; i++ {
		colors[i] = -1
	}

	points := make([]*Point, n)
	for i := 0; i < n; i++ {
		points[i] = &Point{name: i}
	}

	for i := 0; i < m; i++ {
		scanner.Scan()
		me := toInt(scanner.Text()) - 1
		scanner.Scan()
		you := toInt(scanner.Text()) - 1
		scanner.Scan()
		length := toInt(scanner.Text())
		points[me].becomeFriend(points[you], length)
		points[you].becomeFriend(points[me], length)
	}

	dfs(points[0], 0)

	for _, c := range colors {
		fmt.Println(c)
	}
}

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

type Point struct {
	name    int
	friends map[*Point]int
}

func (p *Point) becomeFriend(friend *Point, length int) {
	p.friends[friend] = length
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

