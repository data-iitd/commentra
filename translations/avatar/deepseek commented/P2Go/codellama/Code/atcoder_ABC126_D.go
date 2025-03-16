
package main

import (
    "fmt"
)

// Define the Node struct to represent each node in the graph
type Node struct {
    val   int
    color bool
    a     [][]int
}

// Read the number of nodes in the graph
var n int
fmt.Scan(&n)

// Create a slice to store all nodes
nodes := make([]Node, n)
for i := 0; i < n; i++ {
    nodes[i] = Node{val: i + 1}
}

// Read each edge in the graph and establish connections between nodes
for i := 0; i < n-1; i++ {
    var u, v, w int
    fmt.Scan(&u, &v, &w)
    node1 := &nodes[u-1]
    node2 := &nodes[v-1]
    node1.val = u
    node2.val = v
    node1.a = append(node1.a, []int{node2, w})
    node2.a = append(node2.a, []int{node1, w})
}

// Set the root node to the first node in the list
root := &nodes[0]

// Set the color of the root node to True
root.color = true

// Initialize a set to keep track of visited nodes
nodeSet := make(map[*Node]bool)

// Define the traverse function to recursively traverse the graph
func traverse(node *Node, distance int) {
    if nodeSet[node] {
        return
    } else {
        nodeSet[node] = true
    }
    for _, pair := range node.a {
        adjNode := pair[0]
        dis := pair[1]
        if (distance+dis)%2 == 0 {
            adjNode.color = root.color
        } else {
            adjNode.color = !root.color
        }
        traverse(adjNode, distance+dis)
    }
}

// Call the traverse function starting from the root node with a distance of 0
traverse(root, 0)

// Print the color of each node
for i := 0; i < n; i++ {
    node := &nodes[i]
    if node.color {
        fmt.Println(1)
    } else {
        fmt.Println(0)
    }
}

