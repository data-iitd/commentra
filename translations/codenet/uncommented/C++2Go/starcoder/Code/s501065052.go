package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var N int
    _, err := fmt.Fscanln(reader, &N)
    if err!= nil {
        fmt.Println(err)
        return
    }
    mem := make([]int, N + 1)
    for i := 1; i <= N; i++ {
        var P int
        _, err := fmt.Fscanln(reader, &P)
        if err!= nil {
            fmt.Println(err)
            return
        }
        mem[P] = i
    }

    maxcnt := 1
    cnt := 1
    for i := 1; i < N; i++ {
        if mem[i] < mem[i + 1] {
            cnt++
        } else {
            maxcnt = max(maxcnt, cnt)
            cnt = 1
        }
        if i == N - 1 {
            maxcnt = max(maxcnt, cnt)
        }
    }
    fmt.Println(N - maxcnt)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

