package main
import (
    "fmt"
    "sort"
)
type pair struct {
    i int
    x int
}
func main() {
    var N int
    fmt.Scanf("%d", &N)
    A := make([]pair, N)
    for i := 0; i < N; i++ {
        fmt.Scanf("%d", &A[i].x)
        A[i].i = i + 1
    }
    sort.Slice(A, func(i, j int) bool { return A[i].x < A[j].x })
    for i := 0; i < N - 1; i++ {
        fmt.Printf("%d ", A[i].i)
    }
    fmt.Printf("%d\n", A[N-1].i)
}
