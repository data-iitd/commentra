
###
# Code
###

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to read an array of integers from standard input
func readInts() []int {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    line := scanner.Text()
    parts := strings.Split(line, " ")
    var ints []int
    for _, part := range parts {
        i, _ := strconv.Atoi(part)
        ints = append(ints, i)
    }
    return ints
}

// Description: Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
func dfs(g map[int]map[int]bool, seen map[int]bool, i int) (int, int) {
    // Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
    if seen[i] {
        return 0, 0
    }

    // Mark the current vertex as visited by adding it to the seen set
    seen[i] = true

    // Initialize nodes and edges counters
    nodes := 1
    edges := len(g[i])

    // Recursively traverse the graph for all neighbors of the current vertex
    for j := range g[i] {
        // Recursive call to DFS function for the neighbor vertex
        x, y := dfs(g, seen, j)

        // Update nodes and edges counters based on the result of the recursive call
        nodes += x
        edges += y
    }

    // Return the final count of nodes and edges for the current vertex
    return nodes, edges
}

// Main function to solve the problem
func solve() bool {
    // Read the first line of input containing the number of vertices and edges in the graph
    line0 := readInts()
    if len(line0) == 0 {
        // If there is no more input, return False to indicate the end of the program
        return false
    }

    n, m := line0[0], line0[1]

    // Initialize the graph as a dictionary with vertices as keys and empty sets as values
    g := make(map[int]map[int]bool)
    seen := make(map[int]bool)

    // Initialize an empty dictionary to store the neighbors of each vertex
    for i := 1; i <= n; i++ {
        g[i] = make(map[int]bool)
    }

    // Read the remaining lines of input containing the edges of the graph and add them to the graph
    for _ = 0; m > 0; m-- {
        line := readInts()
        a, b := line[0], line[1]
        g[a][b] = true
        g[b][a] = true
    }

    // Initialize the answer counter to 0
    ans := 0

    // Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
    for i := 1; i <= n; i++ {
        if!seen[i] {
            nodes, edges := dfs(g, seen, i)
            if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {
                ans++
            }
        }
    }

    // Update the answer counter based on the parity of the total number of vertices
    if (n-ans)%2 == 1 {
        ans++
    }

    // Print the final answer and return True to indicate the success of the program
    fmt.Println(ans)
    return true
}

// Main loop to repeatedly call the solve function until there is no more input
func main() {
    for solve() {
    }
}

