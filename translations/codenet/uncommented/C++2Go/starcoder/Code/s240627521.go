package main
import "fmt"

func main() {
    var N int
    fmt.Scan(&N)
    A := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scan(&A[i])
    }
    sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
    var index int
    var max int = 1e9
    for i := 1; i < N; i++ {
        if max > abs(A[0]-2*A[i]) {
            max = abs(A[0]-2*A[i])
            index = i
        }
    }
    fmt.Println(A[0], A[index])
}

