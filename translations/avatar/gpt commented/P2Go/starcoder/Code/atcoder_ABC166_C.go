// Read the values of n (number of nodes) and m (number of edges) from input
n, m := 0, 0
fmt.Scanf("%d %d", &n, &m)

// Create a list of nodes from 1 to n
p := make([]int, n)
for i := 0; i < n; i++ {
    p[i] = i + 1
}

// Read the health points for each node from input
h := make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scanf("%d", &h[i])
}

// Create a dictionary to map each node to its corresponding health points
hp := make(map[int]int)
for i := 0; i < n; i++ {
    hp[p[i]] = h[i]
}

// Initialize a dictionary to represent the graph as an adjacency list
// Each node will map to a list of its connected nodes (edges)
path := make(map[int][]int)
for i := 0; i < n; i++ {
    path[p[i]] = make([]int, 0)
}

// Read m edges from input and populate the adjacency list
for i := 0; i < m; i++ {
    a, b := 0, 0
    fmt.Scanf("%d %d", &a, &b)
    path[a] = append(path[a], b)  // Add edge from a to b
    path[b] = append(path[b], a)  // Add edge from b to a (undirected graph)
}

// Initialize a counter for nodes that have no neighbors with equal or higher health points
c := 0

// Iterate through each node and its connected nodes
for i, v := range path {
    f := 0  // Flag to check if any neighbor has equal or higher health points
    for j := range v {
        // Check if the current node's health is less than or equal to any of its neighbors
        if hp[i] <= hp[v[j]] {
            f = 1  // Set flag if a neighbor with equal or higher health is found
            break  // No need to check further neighbors
        }
    }
    // If no neighbors have equal or higher health points, increment the counter
    if f == 0 {
        c++
    }
}

// Print the count of nodes that have no neighbors with equal or higher health points
fmt.Println(c)

