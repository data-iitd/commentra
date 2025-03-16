
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func readInts() []int {  // Function to read integers from input
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    parts := strings.Split(scanner.Text(), " ")
    var ints []int
    for _, part := range parts {
        intPart, _ := strconv.Atoi(part)
        ints = append(ints, intPart)
    }
    return ints
}

func dfs(g map[int]map[int]bool, seen map[int]bool, i int) (int, int) {  // Depth-First Search to count nodes and edges in a graph
    if seen[i] {  // If node is already seen, return 0, 0
        return 0, 0
    }
    seen[i] = true  // Mark the node as seen
    nodes := 1  // Initialize node count
    edges := len(g[i])  // Count edges from the current node
    for j := range g[i] {  // Traverse all adjacent nodes
        x, y := dfs(g, seen, j)  // Recursively call dfs for each adjacent node
        nodes += x  // Update node count
        edges += y  // Update edge count
    }
    return nodes, edges  // Return the count of nodes and edges
}

func solve() bool {  // Main function to solve the problem
    line0 := readInts()  // Read the first line of input
    if len(line0) == 0 {  // Return False if EOF is encountered
        return false
    }
    n, m := line0[0], line0[1]  // Unpack the number of nodes and edges
    g := make(map[int]map[int]bool)  // Initialize an empty graph
    seen := make(map[int]bool)  // Initialize an empty set to keep track of visited nodes
    for i := 1; i <= n; i++ {  // Initialize the graph with empty sets for each node
        g[i] = make(map[int]bool)
    }
    for _ = 0; _ < m; _++ {  // Read each edge and add it to the graph
        a, b := readInts()
        g[a][b] = true
        g[b][a] = true
    }
    ans := 0  // Initialize the answer variable
    for i := 1; i <= n; i++ {  // Traverse each node in the graph
        if!seen[i] {  // If the node is not seen, perform DFS
            nodes, edges := dfs(g, seen, i)  // Get the count of nodes and edges
            if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {  // Check the conditions
                ans++  // Increment the answer if the conditions are met
            }
        }
    }
    if (n-ans)%2 == 1 {  // Check if the number of disconnected components is odd
        ans++  // Increment the answer if necessary
    }
    fmt.Println(ans)  // Print the final answer
    return true  // Return True to continue the loop
}

func main() {
    for solve() {  // Continuously call solve until it returns False
        // Do nothing
    }
}

