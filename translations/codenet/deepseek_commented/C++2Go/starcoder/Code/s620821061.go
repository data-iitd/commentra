<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// BitMatching is a data structure to solve the bipartite matching problem
type BitMatching struct {
<<<<<<< HEAD
    G [2*MN][]int // Graph representation using adjacency list
    match [2*MN]int // Array to store the match of each node
    used [2*MN]bool // Array to keep track of used nodes in DFS
=======
    G [200000]int
    match [200000]int
    used [200000]bool
>>>>>>> 98c87cb78a (data updated)
}

// NewBitMatching returns a new instance of BitMatching
func NewBitMatching() *BitMatching {
    bm := new(BitMatching)
<<<<<<< HEAD
    for i := 0; i < 2*MN; i++ {
        bm.G[i] = make([]int, 0) // Clear all edges
=======
    for i := 0; i < 200000; i++ {
        bm.G[i] = make([]int, 0)
>>>>>>> 98c87cb78a (data updated)
    }
    return bm
}

// Init initializes the graph
func (bm *BitMatching) Init() {
<<<<<<< HEAD
    for i := 0; i < 2*MN; i++ {
        bm.G[i] = bm.G[i][:0] // Clear all edges
=======
    for i := 0; i < 200000; i++ {
        bm.G[i] = bm.G[i][:0]
>>>>>>> 98c87cb78a (data updated)
    }
}

// Add adds an edge between node a and node b in the bipartite graph
func (bm *BitMatching) Add(a, b int) {
<<<<<<< HEAD
    bm.G[a] = append(bm.G[a], b+MN) // Add edge from a to b+MN
    bm.G[b+MN] = append(bm.G[b+MN], a) // Add edge from b+MN to a
=======
    bm.G[a] = append(bm.G[a], b+100000)
    bm.G[b+100000] = append(bm.G[b+100000], a)
>>>>>>> 98c87cb78a (data updated)
}

// Dfs performs depth-first search to find augmenting paths
func (bm *BitMatching) Dfs(v int) bool {
<<<<<<< HEAD
    bm.used[v] = true // Mark the node as visited
    for i := 0; i < len(bm.G[v]); i++ {
        u := bm.G[v][i]
        w := bm.match[u]
        if w < 0 || (!bm.used[w] && bm.Dfs(w)) { // If the node is not matched or can find an augmenting path
            bm.match[v] = u // Assign the match
            bm.match[u] = v // Assign the match
            return true // Return true as we found an augmenting path
        }
    }
    return false // Return false if no augmenting path is found
=======
    bm.used[v] = true
    for i := 0; i < len(bm.G[v]); i++ {
        u := bm.G[v][i]
        w := bm.match[u]
        if w < 0 ||!bm.used[w] && bm.Dfs(w) {
            bm.match[v] = u
            bm.match[u] = v
            return true
        }
    }
    return false
>>>>>>> 98c87cb78a (data updated)
}

// Exec executes the bipartite matching algorithm
func (bm *BitMatching) Exec() int {
<<<<<<< HEAD
    res := 0 // Initialize the result
    for i := 0; i < 2*MN; i++ {
        bm.match[i] = -1 // Initialize all matches to -1 (no match)
    }
    for v := 0; v < MN; v++ {
        if bm.match[v] < 0 { // If the node is not matched
            for i := 0; i < 2*MN; i++ {
                bm.used[i] = false // Reset the used array
            }
            if bm.Dfs(v) { // Perform DFS from the node
                res++ // Increment the result if an augmenting path is found
            }
        }
    }
    return res // Return the total number of matches found
=======
    res := 0
    for i := 0; i < 100000; i++ {
        bm.match[i] = -1
    }
    for i := 0; i < 100000; i++ {
        if bm.match[i] < 0 {
            for j := 0; j < 100000; j++ {
                bm.used[j] = false
            }
            if bm.Dfs(i) {
                res++
            }
        }
    }
    return res
>>>>>>> 98c87cb78a (data updated)
}

// Gcd computes the greatest common divisor (GCD) of two numbers
func Gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return Gcd(b, a%b)
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        n, m := 0, 0
        if n, _ = strconv.Atoi(scanner.Text()); n == 0 {
            break
        }
<<<<<<< HEAD
        bm := NewBitMatching() // Create an instance of BitMatching
=======
        bm := NewBitMatching()
>>>>>>> 98c87cb78a (data updated)
        bm.Init()
        a := make([]int, n)
        b := make([]int, m)
        for i := 0; i < n; i++ {
            scanner.Scan()
            a[i], _ = strconv.Atoi(scanner.Text())
        }
        for i := 0; i < m; i++ {
            scanner.Scan()
            b[i], _ = strconv.Atoi(scanner.Text())
        }
        for i := 0; i < n; i++ {
            for j := 0; j < m; j++ {
<<<<<<< HEAD
                if Gcd(a[i], b[j])!= 1 { // Check if the GCD is not 1
                    bm.Add(i, j) // Add an edge between the corresponding nodes if GCD is not 1
                }
            }
        }
        fmt.Println(bm.Exec()) // Execute the bipartite matching and print the result
=======
                if Gcd(a[i], b[j])!= 1 {
                    bm.Add(i, j)
                }
            }
        }
        fmt.Println(bm.Exec())
>>>>>>> 98c87cb78a (data updated)
    }
}

