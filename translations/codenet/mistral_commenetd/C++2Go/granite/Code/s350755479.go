

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

const maxn = 1e5 + 5

type Node struct {
    x, y, id int
}

type Edge struct {
    u, v, val int
}

var (
    n int
    node [maxn]Node
    e    [maxn << 1]Edge
    par  [maxn]int
)

func cmp1(a, b Node) bool {
    return a.x < b.x
}

func cmp2(a, b Node) bool {
    return a.y < b.y
}

func init() {
    for i := 0; i <= n; i++ {
        par[i] = i
    }
}

func findpar(x int) int {
    if par[x] == x {
        return x
    }
    par[x] = findpar(par[x])
    return par[x]
}

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
    fmt.Fscanf(reader, "%d\n", &n)

    init()

    for i := 1; i <= n; i++ {
        fmt.Fscanf(reader, "%d%d\n", &node[i].x, &node[i].y)
        node[i].id = i
    }

    sort.Slice(node[1:n+1], func(i, j int) bool {
        return node[i].x < node[j].x
    })

    cnt := 0
    for i := 2; i <= n; i++ {
        e[cnt] = Edge{node[i-1].id, node[i].id, node[i].x - node[i-1].x}
        cnt++
    }

    sort.Slice(node[1:n+1], func(i, j int) bool {
        return node[i].y < node[j].y
    })

    for i := 2; i <= n; i++ {
        e[cnt] = Edge{node[i-1].id, node[i].id, node[i].y - node[i-1].y}
        cnt++
    }

    sort.Slice(e[:cnt], func(i, j int) bool {
        return e[i].val < e[j].val
    })

    ans := int64(0)
    for i := 0; i < cnt; i++ {
        u, v, val := e[i].u, e[i].v, e[i].val
        if findpar(u) == findpar(v) {
            continue
        }
        unite(u, v)
        ans += int64(val)
    }

    fmt.Println(ans)
}

Translate the above Go code to Python and end with comment "