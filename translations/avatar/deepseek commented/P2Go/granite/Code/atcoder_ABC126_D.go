

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define the Node struct to represent each node in the graph
type Node struct {
    val  int
    color bool
    a    []*Node
}

// Read the number of nodes in the graph
func readInt() int {
    sc := bufio.NewScanner(os.Stdin)
    sc.Split(bufio.ScanWords)
    var n int
    sc.Scan()
    n, _ = strconv.Atoi(sc.Text())
    return n
}

// Read each edge in the graph and establish connections between nodes
func readEdge() (int, int, int) {
    sc := bufio.NewScanner(os.Stdin)
    sc.Split(bufio.ScanWords)
    var u, v, w int
    sc.Scan()
    u, _ = strconv.Atoi(sc.Text())
    sc.Scan()
    v, _ = strconv.Atoi(sc.Text())
    sc.Scan()
    w, _ = strconv.Atoi(sc.Text())
    return u, v, w
}

// Set the root node to the first node in the list
func setRoot(nodes []*Node) *Node {
    return nodes[0]
}

// Set the color of the root node to True
func setRootColor(root *Node) {
    root.color = true
}

// Initialize a set to keep track of visited nodes
func initNodeSet() map[int]bool {
    return make(map[int]bool)
}

// Define the traverse function to recursively traverse the graph
func traverse(node *Node, distance int, nodeSet map[int]bool) {
    if nodeSet[node.val] {
        return
    }
    nodeSet[node.val] = true
    for _, pair := range node.a {
        adjNode := pair[0]
        dis := pair[1]
        if (distance + dis) % 2 == 0 {
            adjNode.color = root.color
        } else {
            adjNode.color =!root.color
        }
        traverse(adjNode, distance+dis, nodeSet)
    }
}

// Print the color of each node
func printNodeColors(nodes []*Node) {
    for _, node := range nodes {
        if node.color {
            fmt.Println(1)
        } else {
            fmt.Println(0)
        }
    }
}

func main() {
    // Read the number of nodes in the graph
    n := readInt()

    // Create a list to store all nodes
    nodes := make([]*Node, n)
    for i := 0; i < n; i++ {
        nodes[i] = &Node{}
    }

    // Read each edge in the graph and establish connections between nodes
    for i := 0; i < n-1; i++ {
        u, v, w := readEdge()
        nodes[u-1].val = u
        nodes[v-1].val = v
        nodes[u-1].a = append(nodes[u-1].a, []*Node{nodes[v-1], w})
        nodes[v-1].a = append(nodes[v-1].a, []*Node{nodes[u-1], w})
    }

    // Set the root node to the first node in the list
    root := setRoot(nodes)

    // Set the color of the root node to True
    setRootColor(root)

    // Initialize a set to keep track of visited nodes
    nodeSet := initNodeSet()

    // Call the traverse function starting from the root node with a distance of 0
    traverse(root, 0, nodeSet)

    // Print the color of each node
    printNodeColors(nodes)
}

