package main
import "fmt"

func main() {
    var n int
    fmt.Scanf("%d\n", &n)
    ans := make([]int, n)
    for i := 0; i < n-1; i++ {
        var a int
        fmt.Scanf("%d\n", &a)
        a--
        ans[a]++
    }
    for i := 0; i < n; i++ {
        fmt.Printf("%d\n", ans[i])
    }
}

