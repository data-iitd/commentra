

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
    fmt.Println("Enter the number of elements N:")
    N, _ := strconv.Atoi(reader.ReadLine()[0])
    A := make([]int, N)
    fmt.Println("Enter", N, "integers:")
    for i := 0; i < N; i++ {
        input := reader.ReadLine()
        A[i], _ = strconv.Atoi(strings.TrimSpace(string(input)))
    }
    if possible(N, A) {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

func possible(N int, A []int) bool {
    sum := 0
    for i := 0; i < N; i++ {
        sum += A[i]
    }
    NS := N * (N + 1) / 2
    if sum%NS!= 0 {
        return false
    }
    K := sum / NS
    for i := 0; i < N; i++ {
        j := (i - 1 + N) % N
        d := K - (A[i] - A[j])
        if d < 0 || d%N!= 0 {
            return false
        }
    }
    return true
}

