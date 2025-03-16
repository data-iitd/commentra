package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input containing the number of nodes 'n' and edges 'm'
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	// Initialize a slice 'p' of numbers from 1 to 'n'
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i + 1
	}

	// Read the second line of input containing the heights of the nodes
	scanner.Scan()
	hights := strings.Split(scanner.Text(), " ")
	var h []int
	for _, height := range hights {
		hi, _ := strconv.Atoi(height)
		h = append(h, hi)
	}

	// Create a map 'hp' to store node number as key and height as value
	hp := make(map[int]int)
	for i := 0; i < n; i++ {
		hp[p[i]] = h[i]
	}

	// Initialize a map 'path' to store the graph
	path := make(map[int][]int)
	for i := 1; i <= n; i++ {
		path[i] = []int{}
	}

	// Read 'm' lines of input containing edges and add them to the 'path' map
	for i := 0; i < m; i++ {
		scanner.Scan()
		edge := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(edge[0])
		b, _ := strconv.Atoi(edge[1])
		path[a] = append(path[a], b)
		path[b] = append(path[b], a)
	}

	// Initialize a counter 'c' to store the number of valid paths
	c := 0

	// Iterate through each node in the graph and check if it forms a valid path
	for i := 1; i <= n; i++ {
		// Initialize a flag 'f' to check if the current node is a valid starting point
		f := 0
		// Iterate through each neighbor of the current node and check if it is a valid ending point
		for _, j := range path[i] {
			// If the height of the current node is less than or equal to the height of its neighbor,
			// then it is not a valid path and we set the flag 'f' to 1 and break the loop
			if hp[i] <= hp[j] {
				f = 1
				break
			}
		}
		// If the flag 'f' is still 0 after checking all neighbors, then this node forms a valid path
		// and we increment the counter 'c'
		if f == 0 {
			c += 1
		}
	}

	// Print the final result, i.e., the number of valid paths
	fmt.Println(c)
}
