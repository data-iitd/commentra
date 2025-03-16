package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

type pp struct {
    name string
    t    int
}

var (
    Q [100005]pp
    head, tail, n int
)

func enqueue(x pp) {
    Q[tail] = x
    tail = (tail + 1) % 100005
}

func dequeue() pp {
    x := Q[head]
    head = (head + 1) % 100005
    return x
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func main() {
    var elaps, c int
    var i, q int
    var u pp
    fmt.Scanf("%d %d\n", &n, &q)

    for i = 1; i <= n; i++ {
        fmt.Scanf("%s\n", &Q[i].name)
        fmt.Scanf("%d\n", &Q[i].t)
    }
    head = 1
    tail = n + 1

    for head!= tail {
        u = dequeue()
        c = min(q, u.t)
        u.t -= c
        elaps += c
        if u.t > 0 {
            enqueue(u)
        } else {
            fmt.Printf("%s %d\n", u.name, elaps)
        }
    }

    fmt.Printf("