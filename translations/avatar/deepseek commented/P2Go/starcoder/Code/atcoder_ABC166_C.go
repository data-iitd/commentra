// Step 1: Input the number of nodes (n) and the number of edges (m)
n, m := 0, 0
fmt.Scanf("%d %d", &n, &m)

// Step 2: Create a list of positions (p) from 1 to n
p := make([]int, n)
for i := 0; i < n; i++ {
    p[i] = i + 1
}

// Step 3: Input the heights (h) of the nodes
h := make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scanf("%d", &h[i])
}

// Step 4: Create a dictionary (hp) mapping positions to heights
hp := make(map[int]int)
for i := 0; i < n; i++ {
    hp[p[i]] = h[i]
}

// Step 5: Initialize a dictionary (path) to store the adjacency list of the graph
path := make(map[int][]int)
for i := 0; i < n; i++ {
    path[p[i]] = make([]int, 0)
}

// Step 6: Input the edges of the graph and populate the adjacency list
for i := 0; i < m; i++ {
    a, b := 0, 0
    fmt.Scanf("%d %d", &a, &b)
    path[a] = append(path[a], b)
    path[b] = append(path[b], a)
}

// Step 7: Count the number of nodes that are the highest in their neighborhoods
c := 0
for i, v := range path {
    f := false
    for j := range v {
        if hp[i] <= hp[v[j]] {
            f = true
            break
        }
    }
    if f == false {
        c += 1
    }
}

// Step 8: Output the count of such nodes
fmt.Printf("%d\n", c)

