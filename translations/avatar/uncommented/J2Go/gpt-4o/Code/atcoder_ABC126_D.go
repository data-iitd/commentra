package main

import (
	"fmt"
)

type Point struct {
	name    int
	friends map[*Point]int
}

var colors []int

func main() {
	var n int
	fmt.Scan(&n)
	m := n - 1
	colors = make([]int, n)
	for i := range colors {
		colors[i] = -1
	}
	points := make([]*Point, n)
	for i := 0; i < n; i++ {
		points[i] = &Point{name: i, friends: make(map[*Point]int)}
	}
	for m > 0 {
		m--
		var me, you, length int
		fmt.Scan(&me, &you, &length)
		me-- // Convert to zero-based index
		you-- // Convert to zero-based index
		points[me].becomeFriend(points[you], length)
		points[you].becomeFriend(points[me], length)
	}
	dfs(points[0], 0)
	for _, c := range colors {
		fmt.Println(c)
	}
}

func dfs(p *Point, length int) {
	if colors[p.name] != -1 {
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

func (p *Point) becomeFriend(friend *Point, length int) {
	p.friends[friend] = length
}

// <END-OF-CODE>
