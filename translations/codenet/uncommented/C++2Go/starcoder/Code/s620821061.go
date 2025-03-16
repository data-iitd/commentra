package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

const MN = 520

type BitMatching struct {
    G [2*MN][]int
    match [2*MN]int
    used [2*MN]bool
}

func (bm *BitMatching) init() {
    for i := 0; i < 2*MN; i++ {
        bm.G[i] = bm.G[i][:0]
    }
}

func (bm *BitMatching) add(a, b int) {
    bm.G[a] = append(bm.G[a], b+MN)
    bm.G[b+MN] = append(bm.G[b+MN], a)
}

func (bm *BitMatching) dfs(v int) bool {
    bm.used[v] = true
    for i := 0; i < len(bm.G[v]); i++ {
        u := bm.G[v][i]
        w := bm.match[u]
        if w < 0 || (!bm.used[w] && bm.dfs(w)) {
            bm.match[v] = u
            bm.match[u] = v
            return true
        }
    }
    return false
}

func (bm *BitMatching) exec() int {
    res := 0
    for v := 0; v < MN; v++ {
        if bm.match[v] < 0 {
            for i := 0; i < 2*MN; i++ {
                bm.used[i] = false
            }
            if bm.dfs(v) {
                res++
            }
        }
    }
    return res
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
            continue
        }
        n, m := 0, 0
        fmt.Sscanf(line, "%d %d", &n, &m)
        if n == 0 {
            break
        }
        a := make([]int, n)
        b := make([]int, m)
        for i := 0; i < n; i++ {
            line, err = in.ReadString('\n')
            if err!= nil {
                break
            }
            line = strings.TrimSpace(line)
            fmt.Sscanf(line, "%d", &a[i])
        }
        for i := 0; i < m; i++ {
            line, err = in.ReadString('\n')
            if err!= nil {
                break
            }
            line = strings.TrimSpace(line)
            fmt.Sscanf(line, "%d", &b[i])
        }
        bm := &BitMatching{}
        bm.init()
        for i := 0; i < n; i++ {
            for j := 0; j < m; j++ {
                if gcd(int64(a[i]), int64(b[j]))!= 1 {
                    bm.add(i, j)
                }
            }
        }
        fmt.Println(bm.exec())
    }
}

