package main

import (
    "fmt"
    "sort"
)

type Node struct {
    x, y, id int
}

type Edge struct {
    u, v, val int
}

func cmp1(a, b Node) bool {
    return a.x < b.x
}

func cmp2(a, b Node) bool {
    return a.y < b.y
}

func init() {
    for i := 0; i <= n; i ++ {
        par[i] = i
    }
}

func findpar(x int) int {
    if par[x] == x {
        return x
    }
    return par[x] = findpar(par[x])
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
    var n int
    fmt.Scanf("%d", &n)

    init()

    for i := 1; i <= n; i ++ {
        fmt.Scanf("%d%d", &node[i].x, &node[i].y)
        node[i].id = i
    }

    sort.Slice(node[1:], func(i, j int) bool {
        return node[i].x < node[j].x
    })

    cnt := 0
    for i := 2; i <= n; i ++ {
        e[cnt] = Edge{node[i - 1].id, node[i].id, node[i].x - node[i - 1].x}
        cnt ++
    }

    sort.Slice(node[1:], func(i, j int) bool {
        return node[i].y < node[j].y
    })
    for i := 2; i <= n; i ++ {
        e[cnt] = Edge{node[i - 1].id, node[i].id, node[i].y - node[i - 1].y}
        cnt ++
    }

    sort.Slice(e[:cnt], func(i, j int) bool {
        return e[i].val < e[j].val
    })

    ans := int64(0)
    for i := 0; i < cnt; i ++ {
        u := e[i].u
        v := e[i].v
        val := e[i].val
        if findpar(u) == findpar(v) {
            continue
        }
        unite(u, v)
        ans += int64(val)
    }

    fmt.Println(ans)
}

