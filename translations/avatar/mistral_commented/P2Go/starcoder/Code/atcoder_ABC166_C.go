#######
// Code
#######

// Read the first line of input containing the number of nodes 'n' and edges'm'
var n, m int
fmt.Scanf("%d %d", &n, &m)

// Initialize a list 'p' of numbers from 1 to 'n'
p := make([]int, n)
for i := range p {
    p[i] = i + 1
}

// Read the second line of input containing the heights of the nodes
h := make([]int, n)
fmt.Scanf("%d %d %d %d", &h[0], &h[1], &h[2], &h[3])

// Create a dictionary 'hp' using list comprehension to store node number as key and height as value
hp := make(map[int]int)
for i, v := range p {
    hp[v] = h[i]
}

// Initialize an empty dictionary 'path' to store the graph
path := make(map[int][]int)
for i := range p {
    path[i] = make([]int, 0)
}

// Read'm' lines of input containing edges and add them to the 'path' dictionary
for i := 0; i < m; i++ {
    var a, b int
    fmt.Scanf("%d %d", &a, &b)
    path[a] = append(path[a], b)
    path[b] = append(path[b], a)
}

// Initialize a counter 'c' to store the number of valid paths
c := 0

// Iterate through each node in the graph and check if it forms a valid path
for i, v := range path {
    // Initialize a flag 'f' to check if the current node is a valid starting point
    f := 0
    // Iterate through each neighbor of the current node and check if it is a valid ending point
    for j := range v {
        // If the height of the current node is less than or equal to the height of its neighbor,
        // then it is not a valid path and we set the flag 'f' to 1 and break the loop
        if hp[i] <= hp[v[j]] {
            f = 1
            break
        }
    }
    // If the flag 'f' is still 0 after checking all neighbors, then this node forms a valid path
    // and we increment the counter 'c'
    if f == 0 {
        c++
    }
}

// Print the final result, i.e., the number of valid paths
fmt.Println(c)

