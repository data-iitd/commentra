
// Step 1: Input the number of nodes (n) and the number of edges (m)
var n, m int
fmt.Scan(&n, &m)

// Step 2: Create a list of positions (p) from 1 to n
p := make([]int, n)
for i := range p {
    p[i] = i + 1
}

// Step 3: Input the heights (h) of the nodes
h := make([]int, n)
for i := range h {
    fmt.Scan(&h[i])
}

// Step 4: Create a dictionary (hp) mapping positions to heights
hp := make(map[int]int)
for i, v := range p {
    hp[v] = h[i]
}

// Step 5: Initialize a dictionary (path) to store the adjacency list of the graph
path := make(map[int][]int)

// Step 6: Input the edges of the graph and populate the adjacency list
for i := 0; i < m; i++ {
    var a, b int
    fmt.Scan(&a, &b)
    path[a] = append(path[a], b)
    path[b] = append(path[b], a)
}

// Step 7: Count the number of nodes that are the highest in their neighborhoods
c := 0
for i, v := range path {
    f := 0
    for _, j := range v {
        if hp[i] <= hp[j] {
            f = 1
            break
        }
    }
    if f == 0 {
        c++
    }
}

// Step 8: Output the count of such nodes
fmt.Println(c)

