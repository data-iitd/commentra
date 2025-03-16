
// Importing the queue module for implementing Depth First Search (DFS) using a stack
import "container/list"

// Taking the number of vertices (n) and edges (m) as input
var n, m int
fmt.Scanf("%d %d", &n, &m)

// Initializing the visited list and other variables
var vis = make([]int, n + 1)
var ci, cb, cc int
var g = make([][]int, n + 1)

// Function to perform DFS traversal from a given vertex 'x'
func dfs(x int) bool {
    // Creating an empty stack and initializing a flag
    stk := list.New()
    flag := true

    // Pushing the current vertex 'x' into the stack with color '1'
    stk.PushBack(struct{ v, c int }{v: x, c: 1})

    // Traversing the graph until the stack is empty
    for stk.Len() > 0 {
        // Popping the current vertex 'u' from the stack
        u := stk.Back()
        stk.Remove(u)
        u = u.Value.(struct{ v, c int })

        // If the current vertex 'u' is already visited, then check if it has the same color as the previous vertex
        if vis[u.v]!= 0 {
            flag &= (vis[u.v] == u.c)
            continue
        }

        // Mark the current vertex 'u' as visited with the current color 'col'
        vis[u.v] = u.c

        // Recursively traverse all the adjacent vertices of 'u'
        for _, v := range g[u.v] {
            stk.PushBack(struct{ v, c int }{v: v, c: 3 - u.c})
        }
    }

    // Return the flag indicating whether all vertices in the connected component have the same color or not
    return flag
}

// Adding edges to the graph
for i := 0; i < m; i++ {
    var u, v int
    fmt.Scanf("%d %d", &u, &v)
    // Adding an edge between vertices 'u' and 'v' in both the adjacency lists
    g[u] = append(g[u], v)
    g[v] = append(g[v], u)
}

// Finding the number of isolated vertices and connected components
for i := 1; i <= n; i++ {
    // If the current vertex 'i' is not visited yet
    if vis[i] == 0 {
        // If the current vertex 'i' has no edges, then it is an isolated vertex
        if len(g[i]) == 0 {
            ci++
        }
        // Else, perform DFS traversal from the current vertex 'i' and count the number of connected components
        else {
            if dfs(i) {
                cb++
            } else {
                cc++
            }
        }
    }
}

// Calculating and printing the final answer
fmt.Printf("%d\n", ci*ci+2*ci*(n-ci)+cc*cc+2*cb*cc+2*cb*cb)

