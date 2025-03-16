
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a struct to represent each node in the graph
type Node struct {
	val  int
	color bool
	a    []*Node // Adjacency list to store connected nodes and weights
}

func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of nodes from input
	n, _ := strconv.Atoi(readLine(reader))
	nodes := make([]*Node, n)

	// Initialize nodes and store them in a slice
	for i := 0; i < n; i++ {
		nodes[i] = &Node{}
	}

	// Read edges and construct the graph
	for i := 0; i < n-1; i++ {
		u, v, w := readThreeInt64s(reader)
		node1 := nodes[u-1] // Get the first node (adjusting for 0-indexing)
		node2 := nodes[v-1] // Get the second node (adjusting for 0-indexing)
		node1.val = int(u)  // Set the value of the first node
		node2.val = int(v)  // Set the value of the second node
		// Add the edge to both nodes' adjacency lists
		node1.a = append(node1.a, &Node{val: int(v), weight: int(w)})
		node2.a = append(node2.a, &Node{val: int(u), weight: int(w)})
	}

	// Set the root node and initialize its color
	root := nodes[0]
	root.color = true // Color the root node as true
	visited := make(map[int]bool) // Map to keep track of visited nodes

	// Define a recursive function to traverse the graph
	var traverse func(node *Node, distance int)
	traverse = func(node *Node, distance int) {
		if visited[node.val] {
			return // Node has already been visited, return
		}
		visited[node.val] = true // Mark the node as visited

		// Iterate through each adjacent node
		for _, adjNode := range node.a {
			// Determine the color of the adjacent node based on the distance
			if (distance + adjNode.weight) % 2 == 0 {
				adjNode.color = root.color // Same color as root
			} else {
				adjNode.color =!root.color // Opposite color to root
			}
			// Recursively traverse to the adjacent node
			traverse(adjNode, distance+adjNode.weight)
		}
	}

	// Start the traversal from the root node with an initial distance of 0
	traverse(root, 0)

	// Output the color of each node
	for i := 0; i < n; i++ {
		if nodes[i].color {
			fmt.Println(1) // Print 1 for true color
		} else {
			fmt.Println(0) // Print 0 for false color
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func readThreeInt64s(reader *bufio.Reader) (int64, int64, int64) {
	res := readNInt64s(reader, 3)
	return res[0], res[1], res[2]
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	str, _, err := reader.ReadLine()
	if err == nil {
		for i, num := range strings.Split(string(str), " ") {
			res[i], _ = strconv.ParseInt(num, 10, 64)
		}
	}
	return res
}

func readInt64(reader *bufio.Reader) int64 {
	res, _, err := reader.ReadLine()
	if err == nil {
		i64, _ := strconv.ParseInt(string(res), 10, 64)
		return i64
	}
	return 0
}

func readInt(reader *bufio.Reader) int {
	resInt64 := readInt64(reader)
	return int(resInt64)
}

func readTwoInt64s(reader *bufio.Reader) (int64, int64) {
	res := readNInt64s(reader, 2)
	return res[0], res[1]
}

func readTwoInts(reader *bufio.Reader) (int, int) {
	res := readNInts(reader, 2)
	return res[0], res[1]
}

func readNInts(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	str, _, err := reader.ReadLine()
	if err == nil {
		for i, num := range strings.Split(string(str), " ") {
			res[i], _ = strconv.Atoi(num)
		}
	}
	return res
}

func readUint64(reader *bufio.Reader) uint64 {
	res, _, err := reader.ReadLine()
	if err == nil {
		ui64, _ := strconv.ParseUint(string(res), 10, 64)
		return ui64
	}
	return 0
}

func readUint32(reader *bufio.Reader) uint32 {
	res, _, err := reader.ReadLine()
	if err == nil {
		ui64, _ := strconv.ParseUint(string(res), 10, 32)
		return uint32(ui64)
	}
	return 0
}

func readUint(reader *bufio.Reader) uint {
	res, _, err := reader.ReadLine()
	if err == nil {
		ui64, _ := strconv.ParseUint(string(res), 10, 64)
		return uint(ui64)
	}
	return 0
}

func readString(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func readBytes(reader *bufio.Reader) []byte {
	line, _, err := reader.ReadLine()
	if err!= nil {
		return []byte{}
	}
	return line
}

func readNBytes(reader *bufio.Reader, n int) []byte {
	res := make([]byte, n)
	x, _, err := reader.Read(res)
	if err!= nil {
		return []byte{}
	} else if x == n {
		return res
	}
	return res[:x]
}

func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of nodes from input
	n, _ := strconv.Atoi(readLine(reader))
	nodes := make([]*Node, n)

	// Initialize nodes and store them in a slice
	for i := 0; i < n; i++ {
		nodes[i] = &Node{}
	}

	// Read edges and construct the graph
	for i := 0; i < n-1; i++ {
		u, v, w := readThreeInt64s(reader)
		node1 := nodes[u-1] // Get the first node (adjusting for 0-indexing)
		node2 := nodes[v-1] // Get the second node (adjusting for 0-indexing)
		node1.val = int(u)  // Set the value of the first node
		node2.val = int(v)  // Set the value of the second node
		// Add the edge to both nodes' adjacency lists
		node1.a = append(node1.a, &Node{val: int(v), weight: int(w)})
		node2.a = append(node2.a, &Node{val: int(u), weight: int(w)})
	}

	// Set the root node and initialize its color
	root := nodes[0]
	root.color = true // Color the root node as true
	visited := make(map[int]bool) // Map to keep track of visited nodes

	// Define a recursive function to traverse the graph
	var traverse func(node *Node, distance int)
	traverse = func(node *Node, distance int) {
		if visited[node.val] {
			return // Node has already been visited, return
		}
		visited[node.val] = true // Mark the node as visited

		// Iterate through each adjacent node
		for _, adjNode := range node.a {
			// Determine the color of the adjacent node based on the distance
			if (distance + adjNode.weight) % 2 == 0 {
				adjNode.color = root.color // Same color as root
			} else {
				adjNode.color =!root.color // Opposite color to root
			}
			// Recursively traverse to the adjacent node
			traverse(adjNode, distance+adjNode.weight)
		}
	}

	// Start the traversal from the root node with an initial distance of 0
	traverse(root, 0)

	// Output the color of each node
	for i := 0; i < n; i++ {
		if nodes[i].color {
			fmt.Println(1) // Print 1 for true color
		} else {
			fmt.Println(0) // Print 0 for false color
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func readThreeInt64s(reader *bufio.Reader) (int64, int64, int64) {
	res := readNInt64s(reader, 3)
	return res[0], res[1], res[2]
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	str, _, err := reader.ReadLine()
	if err == nil {
		for i, num := range strings.Split(string(str), " ") {
			res[i], _ = strconv.ParseInt(num, 10, 64)
		}
	}
	return res
}

func readInt64(reader *bufio.Reader) int64 {
	res, _, err := reader.ReadLine()
	if err == nil {
		i64, _ := strconv.ParseInt(string(res), 10, 64)
		return i64
	}
	return 0
}

func readInt(reader *bufio.Reader) int {
	resInt64 := readInt64(reader)
	return int(resInt64)
}

func readTwoInt64s(reader *bufio.Reader) (int64, int64) {
	res := readNInt64s(reader, 2)
	return res[0], res[1]
}

func readTwoInts(reader *bufio.Reader) (int, int) {
	res := readNInts(reader, 2)
	return res[0], res[1]
}

func readNInts(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	str, _, err := reader.ReadLine()
	if err == nil {
		for i, num := range strings.Split(string(str), " ") {
			res[i], _ = strconv.Atoi(num)
		}
	}
	return res
}

func readUint64(reader *bufio.Reader) uint64 {
	res, _, err := reader.ReadLine()
	if err == nil {
		ui64, _ := strconv.ParseUint(string(res), 10, 64)
		return ui64
	}
	return 0
}

func readUint32(reader *bufio.Reader) uint32 {
	res, _, err := reader.ReadLine()
	if err == nil {
		ui64, _ := strconv.ParseUint(string(res), 10, 32)
		return uint32(ui64)
	}
	return 0
}

func readUint(reader *bufio.Reader) uint {
	res, _, err := reader.ReadLine()
	if err == nil {
		ui64, _ := strconv.ParseUint(string(res), 10, 64)
		return uint(ui64)
	}
	return 0
}

func readString(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func readBytes(reader *bufio.Reader) []byte {
	line, _, err := reader.ReadLine()
	if err!= nil {
		return []byte{}
	}
	return line
}

func readNBytes(reader *bufio.Reader, n int) []byte {
	res := make([]byte, n)
	x, _, err := reader.Read(res)
	if err!= nil {
		return []byte{}
	} else if x == n {
		return res
	}
	return res[:x]
}