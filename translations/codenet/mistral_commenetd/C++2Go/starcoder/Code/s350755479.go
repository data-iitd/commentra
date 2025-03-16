
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

// Node struct to store the x and y coordinates of each node and its id
type Node struct {
    x, y, id int
}

// Edge struct to store the u and v ids of the nodes connected by the edge and the value of the edge
type Edge struct {
    u, v, val int
}

// Global variables
var (
    node [100005]Node
<<<<<<< HEAD
    e    [100005]Edge
=======
    e    [200005]Edge
>>>>>>> 98c87cb78a (data updated)
    par  [100005]int
    n    int
)

// Comparator function for sorting nodes based on their x-coordinates
func cmp1(i, j int) bool {
    return node[i].x < node[j].x
}

// Comparator function for sorting nodes based on their y-coordinates
func cmp2(i, j int) bool {
    return node[i].y < node[j].y
}

// Initialization function for the disjoint set data structure
func init() {
    for i := 0; i <= n; i++ {
        par[i] = i
    }
}

// Function to find the representative of a set
func findpar(x int) int {
<<<<<<< HEAD
    return par[x] = (par[x] == x? x : findpar(par[x]))
=======
    if par[x] == x {
        return x
    }
    return par[x] = findpar(par[x])
>>>>>>> 98c87cb78a (data updated)
}

// Function to merge two sets
func unite(x, y int) {
    x = findpar(x)
    y = findpar(y)
    if x == y {
        return
    }
    par[x] = y
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    fmt.Fscanln(reader, &n)
    init()

    for i := 1; i <= n; i++ {
        fmt.Fscanln(reader, &node[i].x, &node[i].y)
        node[i].id = i
    }

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
        u, v, val := e[i].u, e[i].v, e[i].val
        if findpar(u) == findpar(v) {
            continue
        }
        unite(u, v)
        ans += val
    }

    fmt.Fprintln(writer, ans)
}

