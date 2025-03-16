package main
import "fmt"
func I() int {
    var n int
    fmt.Scan(&n)
    return n
}
func MI() []int {
    var n int
    fmt.Scan(&n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
    }
    return a
}
func LI() []int {
    var n int
    fmt.Scan(&n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
    }
    return a
}
func main() {
    mod := 1000000007
    N, A, B := MI()
    ans := 0
    rep := N / (A + B)
    ans += rep * A
    res := N - rep * (A + B)
    ans += min(res, A)
    fmt.Println(ans)
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
