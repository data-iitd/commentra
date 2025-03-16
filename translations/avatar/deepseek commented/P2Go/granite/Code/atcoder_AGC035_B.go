
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Step 1: Input Reading and Initialization
	// Read the number of nodes N and the number of edges M
	N, M := readTwoNums()

	// Initialize adjacency lists for each node
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = make([]int, 0, 2)
	}

	// Initialize degrees for each node
	degs := make([]int, N)

	// Initialize parity for each node
	parity := make([]int, N)

	// Initialize flag to mark visited nodes
	flag := make([]bool, N)

	// Step 2: Edge and Degree Calculation
	// Read each edge and update adjacency lists and degree lists
	for i := 0; i < M; i++ {
		a, b := readTwoNums()
		a--
		b--
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
		degs[a]++
		degs[b]++
	}

	// If the number of edges M is odd, print -1 and exit
	if M%2!= 0 {
		fmt.Println(-1)
		return
	}

	// Step 3: Heap Initialization
	// Initialize a heap Q with nodes based on their degrees
	type Node struct {
		deg int
		id  int
	}
	Q := make([]*Node, 0, N)
	for i, d := range degs {
		Q = append(Q, &Node{deg: d, id: i})
	}
	sort.Slice(Q, func(i, j int) bool {
		return Q[i].deg < Q[j].deg
	})

	// Step 4: Main Loop
	// Process nodes from the heap
	for len(Q) > 0 {
		node := Q[0]
		Q = Q[1:]

		// If the node has already been processed, skip to the next iteration
		if flag[node.id] {
			continue
		}

		// Mark the node as processed
		flag[node.id] = true

		// For each neighbor of the node, update the adjacency list and degree list
		for _, v := range edges[node.id] {
			edges[v] = remove(edges[v], node.id)

			// Print the edge in the required format, alternating the direction based on the parity
			if parity[node.id]!= 0 {
				fmt.Printf("%d %d\n", node.id+1, v+1)
				parity[node.id] = 1 - parity[node.id]
			} else {
				fmt.Printf("%d %d\n", v+1, node.id+1)
				parity[v] = 1 - parity[v]
			}

			// Update the degree and push the updated node back into the heap
			degs[v]--
			Q = append(Q, &Node{deg: degs[v], id: v})
		}
	}

	// Step 5: Output
	// The code prints the edges in the required format, alternating the direction based on the parity
}

func readTwoNums() (a int, b int) {
	reader := bufio.NewReader(os.Stdin)

	res := readNNums(reader, 2)

	a, b = res[0], res[1]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readOneNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func remove(arr []int, x int) []int {
	n := len(arr)
	j := 0
	for i := 0; i < n; i++ {
		if arr[i]!= x {
			arr[j] = arr[i]
			j++
		}
	}
	return arr[:j]
}