

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	path = 0
	cycle = 1
)

type Graph struct {
	adjacencyList []LinkedList
	seen           []bool
	count          int
}

type LinkedList struct {
	value int
	next  *LinkedList
}

func (l *LinkedList) Add(value int) {
	l.value = value
	l.next = nil
}

func (g *Graph) Dfs(child, par int) int {
	if g.seen[child] {
		return cycle
	}
	g.seen[child] = true
	for node := g.adjacencyList[child].next; node!= nil; node = node.next {
		if node.value!= par {
			g.count++
			if g.Dfs(node.value, child) == cycle {
				return cycle
			}
		}
	}
	return path
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	m, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	g := Graph{
		adjacencyList: make([]LinkedList, m+1),
		seen:           make([]bool, m+1),
	}
	for i := 0; i < n; i++ {
		x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		y, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		g.adjacencyList[x].Add(y)
		g.adjacencyList[y].Add(x)
	}
	toRemove := 0
	for i := 1; i <= m; i++ {
		if!g.seen[i] {
			g.count = 0
			if g.Dfs(i, 0) == cycle {
				if g.count%2 == 1 {
					toRemove++
				}
			}
		}
	}
	if (m-toRemove)%2 == 1 {
		toRemove++
	}
	fmt.Println(toRemove)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

