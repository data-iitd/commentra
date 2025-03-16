package main
import (
    "fmt"
    "math"
    "sort"
    "strings"
)
func main() {
    var N int
    fmt.Scan(&N)
    A := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scan(&A[i])
    }
    A = A[:len(A)-1]
    N = len(A)
    i := 1
    ans := 0
    for i < N-1 {
        if A[i-1] < A[i] > A[i+1] || A[i-1] > A[i] < A[i+1] {
            ans++
            i++
        }
        i++
    }
    fmt.Println(ans + 1)
}
