<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

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

// Define a structure for nodes with x, y coordinates and an id
type Node struct {
    x, y, id int
}

// Define a structure for edges with u, v nodes and a value
type Edge struct {
    u, v, val int
}

// Define an array for nodes
var node [maxn]Node

// Define an array for edges
var e [maxn << 1]Edge

// Define an array for storing the parent of each node
var par [maxn]int

// Define an integer for the number of nodes
var n int

// Define a comparison function to sort nodes by x coordinate
func cmp1(a, b Node) bool {
    return a.x < b.x
}

// Define a comparison function to sort nodes by y coordinate
func cmp2(a, b Node) bool {
    return a.y < b.y
}

// Define a function to initialize the parent array
func init() {
    for i := 0; i <= n; i++ {
        par[i] = i
    }
}

// Define a function to find the root of a node using path compression
func findpar(x int) int {
    if par[x] == x {
        return x
    }
    return par[x] = findpar(par[x])
}

// Define a function to merge two sets
func unite(x, y int) {
    x = findpar(x)
    y = findpar(y)
    if x == y {
        return
    }
    par[x] = y
}

// Define a function to read input from stdin
func readInput() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanln(reader, &n)
    for i := 1; i <= n; i++ {
        fmt.Fscanln(reader, &node[i].x, &node[i].y)
        node[i].id = i
    }
}

// Define a function to output the total weight of the minimum spanning tree
func output() {
    sort.Slice(node[1:], func(i, j int) bool {
        return node[i+1].x < node[j+1].x
    })
    sort.Slice(node[1:], func(i, j int) bool {
        return node[i+1].y < node[j+1].y
    })
    cnt := 0
    for i := 2; i <= n; i++ {
        e[cnt] = Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x}
        cnt++
    }
    for i := 2; i <= n; i++ {
        e[cnt] = Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y}
        cnt++
    }
    sort.Slice(e[:cnt], func(i, j int) bool {
        return e[i].val < e[j].val
    })
    ans := 0
    for i := 0; i < cnt; i++ {
        u := e[i].u
        v := e[i].v
        val := e[i].val
        if findpar(u) == findpar(v) {
            continue
        }
        unite(u, v)
        ans += val
    }
    fmt.Println(ans)
}

func main() {
    readInput()
    init()
<<<<<<< HEAD
    sort.Slice(node[1:], cmp1)
    cnt := 0
    for i := 2; i <= n; i++ {
        e[cnt] = Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x}
        cnt++
    }
    sort.Slice(node[1:], cmp2)
    for i := 2; i <= n; i++ {
        e[cnt] = Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y}
        cnt++
    }
    sort.Slice(e[:cnt], func(i, j int) bool {
        return e[i].val < e[j].val
    })
    ans := 0
    for i := 0; i < cnt; i++ {
        u := e[i].u
        v := e[i].v
        val := e[i].val
        if findpar(u) == findpar(v) {
            continue
        }
        unite(u, v)
        ans += val
    }
    fmt.Println(ans)
=======
    output()
>>>>>>> 98c87cb78a (data updated)
}

