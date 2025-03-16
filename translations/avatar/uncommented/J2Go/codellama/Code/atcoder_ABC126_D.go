
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	colors := make([]int, n)
	for i := 0; i < n; i++ {
		colors[i] = -1
	}
	points := make([]Point, n)
	for i := 0; i < n; i++ {
		points[i] = Point{i, make(map[Point]int)}
	}
	var m int
	fmt.Scan(&m)
	for i := 0; i < m; i++ {
		var me, you, length int
		fmt.Scan(&me, &you, &length)
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

func (p *Point) becomeFriend(p2 *Point, length int) {
	p.friends[*p2] = length
}

func dfs(p Point, length int) {
	if colors[p.name] != -1 {
		return
	}
	if length%2 == 0 {
		colors[p.name] = 0
	} else {
		colors[p.name] = 1
	}
	keys := make([]Point, 0, len(p.friends))
	for k := range p.friends {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool {
		return keys[i].name < keys[j].name
	})
	for _, k := range keys {
		dfs(k, length+p.friends[k])
	}
}

// 