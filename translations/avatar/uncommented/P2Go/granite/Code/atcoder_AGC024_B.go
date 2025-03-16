
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    N, _ := fmt.Fscanf(reader, "%d\n", &N)
    P := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Fscanf(reader, "%d\n", &P[i])
    }
    editorial(N, P)
}

func editorial(N int, P []int) {
    if N == 1 {
        fmt.Println(0)
        return
    }
    a := make([]int, N+1)
    for i, p := range P {
        a[p] = i
    }
    tmp := 1
    maxLen := 1
    for i := 1; i < N; i++ {
        if a[i] < a[i+1] {
            tmp += 1
            maxLen = max(maxLen, tmp)
        } else {
            tmp = 1
        }
    }
    ans := N - maxLen
    fmt.Println(ans)
}

func WA(N int, P []int) {
    tmp := 0
    ans := 0
    for i, p := range P {
        if i == 0 || P[i-1]+1 == p {
            tmp += 1
        } else {
            ans = max(ans, tmp)
            tmp = 1
        }
    }
    fmt.Println(N - ans)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// 