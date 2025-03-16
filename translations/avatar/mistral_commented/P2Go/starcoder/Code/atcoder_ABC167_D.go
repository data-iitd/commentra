
// Importing the 'defaultdict' from the 'collections' module
import "container/defaultdict"

// Taking the number of nodes 'N' and the number of edges 'K' as input
var N, K int
fmt.Scanf("%d %d", &N, &K)

// Initializing the list 'L' with the given number of edges
L := make([]int, K)
for i := 0; i < K; i++ {
    fmt.Scanf("%d", &L[i])
}

// Adding a special node with index -1 at the beginning of the list 'L'
L = append([]int{-1}, L...)

// Initializing an empty list 'path' to store the shortest path
path := []int{1}

// Initializing variables 'ind' and 'count'
ind, count := 0, 0

// Initializing variables 'x' and 't'
x, t := 1, -1

// Initializing a boolean variable 'flag'
flag := false

// Creating an empty dictionary 'Hash' using defaultdict
Hash := make(map[int]int)

// Traversing through all the nodes from 0 to 'N'
for i := 0; i <= N; i++ {
    // Getting the next edge 'ne' from the current node 'x'
    ne := L[x]

    // Checking if the current node 'ne' is already in the hash table 'Hash'
    if Hash[ne]!= 0 {
        // Setting the boolean variable 'flag' to True and storing the index of the previous occurrence of the node 'ne' in 't'
        flag = true
        t = Hash[ne]
        break
    }

    // Appending the next edge 'ne' to the list 'path'
    path = append(path, ne)

    // Incrementing the index 'ind' and storing it in the hash table 'Hash' with the key as the current node 'ne' and value as 'ind'
    ind++
    Hash[ne] = ind

    // Updating the current node 'x' to the next node 'ne'
    x = ne
}

// Checking if there is a cycle in the graph
if flag == true {
    // Storing the list of nodes in the cycle 'loop'
    loop := path[t:]

    // Checking if the length of the path is less than 'K'
    if len(path) < K {
        // Printing the 'K'th node in the path
        fmt.Printf("%d\n", path[K])
    }

    // If the length of the path is greater than or equal to 'K', then we need to find the 'K'th node in the cycle 'loop'
    else {
        // Updating the value of 'K' by subtracting the length of the path and taking the modulo with the length of the cycle 'loop'
        K = K - len(path)
        K = K % len(loop)

        // Printing the 'K'th node in the cycle 'loop'
        fmt.Printf("%d\n", loop[K])
}

// If there is no cycle in the graph, then we simply print the 'K'th node in the path
else {
    // Printing the 'K'th node in the path
    fmt.Printf("%d\n", path[K-1])
}

