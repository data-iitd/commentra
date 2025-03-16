package main
import "fmt"
func main() {
    var n, m int
    fmt.Scanf("%d %d", &n, &m)
    round_complexity := make([]int, n)
    george_complexity := make([]int, m)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &round_complexity[i])
    }
    for i := 0; i < m; i++ {
        fmt.Scanf("%d", &george_complexity[i])
    }
    i, j := 0, 0
    for i < n && j < m {
        i++
        if round_complexity[i] <= george_complexity[j] {
            i++
        }
        j++
    }
    fmt.Printf("%d", n-i)
}
