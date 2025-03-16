
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(reader.ReadLine())
    A := make([]int, N)
    for i := 0; i < N; i++ {
        A[i], _ = strconv.Atoi(reader.ReadLine())
    }

    m := A[0]
    M := A[0]
    for i := 0; i < N; i++ {
        if A[i] < m {
            m = A[i]
        }
        if A[i] > M {
            M = A[i]
        }
    }

    fmt.Println(M - m)
}

