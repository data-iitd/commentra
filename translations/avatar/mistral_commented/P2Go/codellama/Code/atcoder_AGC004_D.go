// Set the recursion limit for the function call stack to 1 million
import "runtime"

func init() {
    runtime.GOMAXPROCS(1000000)
}

// Define the depth-first search function 'dfs'
func dfs(links [][]int, n, k, v, p int) (int, int) {
    // Initialize variables for height from leaf node and cut count
    heightFromLeaf := 0
    cutCount := 0

    // Iterate through neighbors of the current node 'v'
    for _, u := range links[v] {
        // Skip if the neighbor is not a valid node (0)
        if u == 0 {
            continue
        }

        // Recursively call the 'dfs' function for the neighbor 'u'
        hgt, cut := dfs(links, n, k, u, v)

        // Update the height from leaf and cut count
        heightFromLeaf = max(heightFromLeaf, hgt)
        cutCount += cut
    }

    // Update the height from leaf and cut count for the current node 'v'
    heightFromLeaf += 1

    // If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    // then this node is a cut vertex and we need to add 1 to the cut count
    if p != 0 && heightFromLeaf == k {
        heightFromLeaf = 0
        cutCount += 1
    }

    // Return the height from leaf and cut count for the current node 'v'
    return heightFromLeaf, cutCount
}

// Read input from standard input
var n, k int
fmt.Scan(&n, &k)

// Initialize the 'links' list with slices for each node
links := make([][]int, n)

// Process the input edges and add them to the 'links' list
for i := 0; i < n-1; i++ {
    var a int
    fmt.Scan(&a)
    a--
    links[a] = append(links[a], i+1)
}

// Call the 'dfs' function with the initial parameters
_, ans := dfs(links, n, k, 0, 0)

// If the first node is not a root node, add 1 to the answer
if aaa[0] != 1 {
    ans++
}

// Print the final answer
fmt.Println(ans)

