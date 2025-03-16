package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Maximum number of vertices
const MN = 520

// BitMatching structure for finding maximum matching in a bipartite graph
type BitMatching struct {
    G [2*MN][]int // Adjacency list for the bipartite graph
    match [2*MN]int // Array to store matches for vertices
    used [2*MN]bool // Array to track visited vertices during DFS
}

// Initializes the graph by clearing the adjacency list
func (bm *BitMatching) init() {
    for i := 0; i < 2*MN; i++ {
        bm.G[i] = bm.G[i][:0]
    }
}

// Adds an edge between vertex a and vertex b in the bipartite graph
// Note: b is adjusted by adding V to differentiate between the two sets
func (bm *BitMatching) add(a, b int) {
    bm.G[a] = append(bm.G[a], b+MN) // Connect a to b in the second set
    bm.G[b+MN] = append(bm.G[b+MN], a) // Connect b to a in the first set
}

// Depth-First Search to find an augmenting path
func (bm *BitMatching) dfs(v int) bool {
    bm.used[v] = true // Mark the current vertex as visited
    for i := 0; i < len(bm.G[v]); i++ {
        u := bm.G[v][i] - MN // Get the matched vertex for u
        w := bm.match[u] // Get the matched vertex for u
        // If u is unmatched or we can find an augmenting path
        if w < 0 || (!bm.used[w] && bm.dfs(w)) {
            bm.match[v] = u // Match v with u
            bm.match[u] = v // Match u with v
            return true // Found a match
        }
    }
    return false // No match found
}

// Executes the matching algorithm and returns the size of the maximum matching
func (bm *BitMatching) exec() int {
    res := 0 // Result variable to count matches
    for i := 0; i < 2*MN; i++ {
        bm.match[i] = -1 // Initialize matches to -1 (unmatched)
    }
    for v := 0; v < MN; v++ {
        if bm.match[v] < 0 { // If vertex v is unmatched
            for i := 0; i < 2*MN; i++ {
                bm.used[i] = false // Reset visited array
            }
            if bm.dfs(v) { // Try to find a match for v
                res++ // Increment the result if a match is found
            }
        }
    }
    return res // Return the total number of matches
}

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a%b)
}

func main() {
    in := bufio.NewReader(os.Stdin)
    for {
        line, err := in.ReadString('\n')
        if err!= nil {
            break
        }
        line = strings.TrimSpace(line)
        if line == "" {
            break
        }
        n, m := strings.Split(line, " ")
        n, _ = strconv.Atoi(n)
        m, _ = strconv.Atoi(m)
        if n == 0 {
            break
        }
        a := make([]int, n)
        b := make([]int, m)
        for i := 0; i < n; i++ {
            line, _ = in.ReadString('\n')
            line = strings.TrimSpace(line)
            a[i], _ = strconv.Atoi(line)
        }
        for i := 0; i < m; i++ {
            line, _ = in.ReadString('\n')
            line = strings.TrimSpace(line)
            b[i], _ = strconv.Atoi(line)
        }

        // Build the bipartite graph based on the GCD condition
        bm := BitMatching{}
        bm.init()
        for i := 0; i < n; i++ {
            for j := 0; j < m; j++ {
                if gcd(a[i], b[j])!= 1 { // If GCD is not 1, add an edge
                    bm.add(i, j)
                }
            }
        }

        // Execute the matching algorithm and print the result
        fmt.Println(bm.exec())
    }
}

