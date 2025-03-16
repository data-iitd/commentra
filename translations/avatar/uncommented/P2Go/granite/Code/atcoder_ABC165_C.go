
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var N, M, Q int
    var a, b, c, d []int
    tokens, _ := reader.ReadLine()
    N, _ = strconv.Atoi(strings.TrimSpace(string(tokens)))
    tokens, _ = reader.ReadLine()
    M, _ = strconv.Atoi(strings.TrimSpace(string(tokens)))
    tokens, _ = reader.ReadLine()
    Q, _ = strconv.Atoi(strings.TrimSpace(string(tokens)))
    a = make([]int, Q)
    b = make([]int, Q)
    c = make([]int, Q)
    d = make([]int, Q)
    for i := 0; i < Q; i++ {
        tokens, _ := reader.ReadLine()
        a[i], _ = strconv.Atoi(strings.TrimSpace(string(tokens)))
    }
    for i := 0; i < Q; i++ {
        tokens, _ := reader.ReadLine()
        b[i], _ = strconv.Atoi(strings.TrimSpace(string(tokens)))
    }
    for i := 0; i < Q; i++ {
        tokens, _ := reader.ReadLine()
        c[i], _ = strconv.Atoi(strings.TrimSpace(string(tokens)))
    }
    for i := 0; i < Q; i++ {
        tokens, _ := reader.ReadLine()
        d[i], _ = strconv.Atoi(strings.TrimSpace(string(tokens)))
    }
    solve(N, M, Q, a, b, c, d)
}

func solve(N, M, Q int, a, b, c, d []int) {
    var res int
    var rec func(A []int)
    rec = func(A []int) {
        if len(A) == N {
            ans := 0
            for i := 0; i < Q; i++ {
                if A[b[i]-1]-A[a[i]-1] == c[i] {
                    ans += d[i]
                }
            }
            if ans > res {
                res = ans
            }
            return
        }
        lastMax := 1
        if len(A) > 0 {
            lastMax = A[len(A)-1]
        }
        for i := lastMax; i <= M; i++ {
            rec(append(A, i))
        }
    }
    rec([]int{})
    fmt.Println(res)
}

