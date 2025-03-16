package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var N int
    _, err := fmt.Fscanln(reader, &N)
    if err!= nil {
        panic(err)
    }
    T := make([]int, N)
    for i := 0; i < N; i++ {
        _, err := fmt.Fscanln(reader, &T[i])
        if err!= nil {
            panic(err)
        }
    }
    var M int
    _, err = fmt.Fscanln(reader, &M)
    if err!= nil {
        panic(err)
    }
    P := make([]int, M)
    X := make([]int, M)
    for i := 0; i < M; i++ {
        _, err = fmt.Fscanln(reader, &P[i], &X[i])
        if err!= nil {
            panic(err)
        }
    }
    solve(N, T, M, P, X)
}

func solve(N int, T []int, M int, P []int, X []int) {
    for i := 0; i < M; i++ {
        ans := 0
        for j := 0; j < N; j++ {
            if j == P[i]-1 {
                ans += X[i]
            } else {
                ans += T[j]
            }
        }
        fmt.Println(ans)
    }
}

