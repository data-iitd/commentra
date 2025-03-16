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
	n, m := 0, 0
	colors := make([]int, 0)
	points := make([]Point, 0)
	for sc.Scan() {
		line := sc.Text()
		if n == 0 {
			n, _ = strconv.Atoi(line)
			colors = make([]int, n)
			points = make([]Point, n)
			for i := 0; i < n; i++ {
				points[i] = Point{i, make(map[int]int)}
			}
		} else {
			m, _ = strconv.Atoi(line)
			m--
			if m == 0 {
				break
			}
			me, _ := strconv.Atoi(strings.Split(line, " ")[0])
			you, _ := strconv.Atoi(strings.Split(line, " ")[1])
			length, _ := strconv.Atoi(strings.Split(line, " ")[2])
			points[me-1].becomeFriend(points[you-1], length)
			points[you-1].becomeFriend(points[me-1], length)
		}
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

func (p *Point) becomeFriend(friend Point, length int) {
	p.friends[friend] = length
}

