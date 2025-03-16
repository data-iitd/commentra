package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Set the recursion limit to a high value to handle deep recursions
func init() {
	recursionLimit := 10000000
	_ = int(^uint(0) >> 1)
	*(*int)(unsafe.Pointer(&recursionLimit)) = recursionLimit
}

// Define a large prime number for modular arithmetic
const mod = 1000000007

// Define infinity for comparison purposes
const INF = int(^uint(0) >> 1)

// Function to read a single integer from input
func inp() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

// Function to read a list of integers from input
func inpl() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

// Read the number of nodes and the starting points for ta and ao
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	ta, _ := strconv.Atoi(parts[1])
	ao, _ := strconv.Atoi(parts[2])
	ta -= 1  // Adjusting to zero-based index
	ao -= 1  // Adjusting to zero-based index

	// Initialize the graph as an adjacency list
	g := make([][]int, n)

	// Read the edges of the graph and populate the adjacency list
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		parts := strings.Split(scanner.Text(), " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		a -= 1  // Adjusting to zero-based index
		b -= 1  // Adjusting to zero-based index
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}

	// Initialize distance arrays for ta and ao
	taDist := make([]int, n)
	for i := range taDist {
		taDist[i] = -1
	}
	taDist[ta] = 0  // Distance to itself is 0

	aoDist := make([]int, n)
	for i := range aoDist {
		aoDist[i] = -1
	}
	aoDist[ao] = 0  // Distance to itself is 0

	// Depth-first search (DFS) function to calculate distances from ta
	var taDFS func(node int)
	taDFS = func(node int) {
		for _, v := range g[node] {
			if taDist[v] != -1 {
				continue  // Skip if already visited
			}
			taDist[v] = taDist[node] + 1  // Update distance
			taDFS(v)  // Recursive DFS call
		}
	}

	// Depth-first search (DFS) function to calculate distances from ao
	var aoDFS func(node int)
	aoDFS = func(node int) {
		for _, v := range g[node] {
			if aoDist[v] != -1 {
				continue  // Skip if already visited
			}
			aoDist[v] = aoDist[node] + 1  // Update distance
			aoDFS(v)  // Recursive DFS call
		}
	}

	// Perform DFS from ao to calculate distances
	aoDFS(ao)

	// Perform DFS from ta to calculate distances
	taDFS(ta)

	// Initialize result variable to track the maximum distance
	res := 0

	// Calculate the maximum distance where ta's distance is less than or equal to ao's distance
	for i := 0; i < n; i++ {
		if taDist[i] > aoDist[i] {
			continue  // Skip if ta is further away than ao
		}
		if aoDist[i] > res {
			res = aoDist[i]  // Update result with the maximum distance
		}
	}

	// Print the result, subtracting 1 to adjust for zero-based indexing
	fmt.Println(res - 1)
}
