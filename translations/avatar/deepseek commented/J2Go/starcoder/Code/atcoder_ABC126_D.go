package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Point struct {
	name   int
	friends map[int]int
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	n, _ := strconv.Atoi(sc.Text())
	m := n - 1
	colors := make([]int, n)
	for i := 0; i < n; i++ {
		colors[i] = -1
	}

	points := make([]Point, n)
	for i := 0; i < n; i++ {
		points[i] = Point{i, make(map[int]int)}
	}

	for m > 0 {
		me, _ := strconv.Atoi(sc.Text())
		you, _ := strconv.Atoi(sc.Text())
		length, _ := strconv.Atoi(sc.Text())
		points[me-1].friends[you-1] = length
		points[you-1].friends[me-1] = length
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

	if length % 2 == 0 {
		colors[p.name] = 0
	} else {
		colors[p.name] = 1
	}

	for friend, length2 := range p.friends {
		dfs(points[friend], length+length2)
	}
}

// 