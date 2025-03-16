package main
import "fmt"

type Node struct {
	val  int
	color bool
	a    []*Node
}

func main() {
	n := 0
	fmt.Scanf("%d", &n)
	nodes := make([]*Node, n)
	for i := 0; i < n; i++ {
		nodes[i] = &Node{}
	}
	for i := 0; i < n - 1; i++ {
		u, v, w := 0, 0, 0
		fmt.Scanf("%d %d %d", &u, &v, &w)
		node1 := nodes[u-1]
		node2 := nodes[v-1]
		node1.val = u
		node2.val = v
		node1.a = append(node1.a, node2)
		node2.a = append(node2.a, node1)
	}
	root := nodes[0]
	root.color = true
	nodeSet := make(map[*Node]bool)
	traverse(root, 0, nodeSet)
	for i := 0; i < n; i++ {
		node := nodes[i]
		if node.color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}

func traverse(node *Node, distance int, nodeSet map[*Node]bool) {
	if nodeSet[node] {
		return
	}
	nodeSet[node] = true
	for _, pair := range node.a {
		adjNode := pair
		dis := distance + pair.val
		if dis%2 == 0 {
			adjNode.color = root.color
		} else {
			adjNode.color =!root.color
		}
		traverse(adjNode, dis, nodeSet)
	}
}

