package main
import "fmt"
import "sort"
func main() {
    var N, X int
    fmt.Scanf("%d %d", &N, &X)
    if X == 1 || X == N*2-1 {
        fmt.Println("No")
        return
    }
    fmt.Println("Yes")
    if X == N*2-2 {
        xs := make([]int, 0, N-1)
        for i := 1; i < N-1; i++ {
            xs = append(xs, i)
        }
        xs = append(xs, X+2, X-1)
    } else {
        xs := make([]int, 0, N-3)
        for i := 1; i < N-3; i++ {
            xs = append(xs, i)
        }
        xs = append(xs, X+2, X-1, X)
        for i := N-3; i < len(xs); i++ {
            xs = append(xs, i)
        }
    }
    fmt.Println(xs)
}
