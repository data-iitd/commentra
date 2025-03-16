package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Define a constant for the maximum number of nodes
const maxn = 1e5 + 5

// Structure to represent a node with coordinates and an ID
type Node struct {
    x, y, id int
}

// Structure to represent an edge with two nodes and a weight
type Edge struct {
    u, v, val int
}

// Array to store the parent of each node for union-find
var par [maxn]int
var n int // Number of nodes

// Comparison function to sort nodes based on their x-coordinate
func cmp1(a, b Node) bool {
    return a.x < b.x
}

// Comparison function to sort nodes based on their y-coordinate
func cmp2(a, b Node) bool {
    return a.y < b.y
}

// Function to initialize the union-find structure
func init() {
    for i := 0; i <= n; i++ {
        par[i] = i
    }
}

// Function to find the representative parent of a node
func findpar(x int) int {
    return par[x] = (par[x] == x? x : findpar(par[x]))
}

// Function to unite two nodes in the union-find structure
func unite(x, y int) {
    x = findpar(x)
    y = findpar(y)
    if x == y {
        return
    }
    par[x] = y
}

func main() {
    // Read the number of nodes
    n, _ = strconv.Atoi(readLine())

    // Initialize the union-find structure
    init()

    // Read the coordinates of each node and assign an ID
    for i := 1; i <= n; i++ {
        x, y := readNums()
        node := Node{x, y, i}
        node.id = i
        node.id = i
        node.id = i
    }

    // Sort nodes based on their x-coordinate
    sort.Slice(node[1:], func(i, j int) bool {
        return node[i].x < node[j].x
    })

    cnt := 0
    // Create edges based on x-coordinates
    for i := 2; i <= n; i++ {
        e[cnt] = Edge{node[i - 1].id, node[i].id, node[i].x - node[i - 1].x}
        cnt++
    }

    // Sort nodes based on their y-coordinate
    sort.Slice(node[1:], func(i, j int) bool {
        return node[i].y < node[j].y
    })
    // Create edges based on y-coordinates
    for i := 2; i <= n; i++ {
        e[cnt] = Edge{node[i - 1].id, node[i].id, node[i].y - node[i - 1].y}
        cnt++
    }

    // Sort edges based on their weight
    sort.Slice(e[:cnt], func(i, j int) bool {
        return e[i].val < e[j].val
    })

    ans := 0
    // Process each edge in sorted order
    for i := 0; i < cnt; i++ {
        u := e[i].u
        v := e[i].v
        val := e[i].val
        // If u and v are already connected, skip this edge
        if findpar(u) == findpar(v) {
            continue
        }
        unite(u, v) // Union the two nodes
        ans += val // Add the weight of this edge to the total
    }

    // Output the total weight of the minimum spanning tree
    fmt.Println(ans)
}

func readLine() string {
    buf := bufio.NewReader(os.Stdin)
    var str string
    for {
        str, _ = buf.ReadString('\n')
        if strings.HasSuffix(str, "\n") {
            break
        }
    }
    return str[:len(str)-1]
}

func readNums() (a int, b int) {
    a, _ = strconv.Atoi(readLine())
    b, _ = strconv.Atoi(readLine())
    return
}

