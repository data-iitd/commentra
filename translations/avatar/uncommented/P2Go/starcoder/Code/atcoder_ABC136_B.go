package main
import "fmt"
func main() {
    var N int
    fmt.Scanf("%d", &N)
    var i int = 1
    var ans int = 0
    for i <= 10 {
        ans += (10 ** i - 10 ** (i - 1))
        i += 2
    }
    ans += max(0, N - 10 ** (i - 1) + 1)
    fmt.Printf("%d", ans)
}
