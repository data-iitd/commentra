
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    N, _ := strconv.Atoi(read())
    G := make([][]int, N)
    for i := 0; i < N-1; i++ {
        x, _ := strconv.Atoi(read())
        y, _ := strconv.Atoi(read())
        x--
        y--
        G[x] = append(G[x], y)
        G[y] = append(G[y], x)
    }
    used := make([]bool, N)
    grundy := make([]int, N)
    dfs(0, G, used, grundy)
    if grundy[0]!= 0 {
        fmt.Fprintln(out, "Alice")
    } else {
        fmt.Fprintln(out, "Bob")
    }
    out.Flush()
}

func dfs(v int, G [][]int, used []bool, grundy []int) {
    used[v] = true
    grundy[v] = 0
    for _, to := range G[v] {
        if!used[to] {
            dfs(to, G, used, grundy)
            grundy[v] ^= (grundy[to] + 1)
        }
    }
}

func read() string {
    buf := make([]byte, 0)
    for {
        line, prefix, err := in.ReadLine()
        if err!= nil {
            panic(err)
        }
        buf = append(buf, line...)
        if prefix == false {
            break
        }
    }
    return string(buf)
}

