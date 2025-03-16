package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	val   int
	color bool
	edges [][2]int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1])

	nodes := make([]Node, n)
	for i := 0; i < n; i++ {
		nodes[i] = Node{val: i + 1}
	}

	for i := 0; i < n-1; i++ {
		line, _ := reader.ReadString('\n')
		parts := bufio.NewScanner(strings.NewReader(line)).Text()
		u, _ := strconv.Atoi(parts[0:1])
		v, _ := strconv.Atoi(parts[2:3])
		w, _ := strconv.Atoi(parts[4:])
		nodes[u-1].edges = append(nodes[u-1].edges, [2]int{v, w})
		nodes[v-1].edges = append(nodes[v-1].edges, [2]int{u, w})
	}

	root := &nodes[0]
	root.color = true
	nodeSet := make(map[*Node]bool)

	var traverse func(*Node, int)
	traverse = func(node *Node, distance int) {
		if _, exists := nodeSet[node]; exists {
			return
		}
		nodeSet[node] = true
		for _, edge := range node.edges {
			adjNode := &nodes[edge[0]-1]
			dis := edge[1]
			if (distance+dis)%2 == 0 {
				adjNode.color = root.color
			} else {
				adjNode.color = !root.color
			}
			traverse(adjNode, distance+dis)
		}
	}

	traverse(root, 0)

	for _, node := range nodes {
		if node.color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}
