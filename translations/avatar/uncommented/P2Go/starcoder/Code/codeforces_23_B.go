package main
import "fmt"
func main() {
    var n int
    fmt.Scanf("%d", &n)
    for i := 0; i < n; i++ {
        var a int
        fmt.Scanf("%d", &a)
        if a < 2 {
            fmt.Println(0)
        }
        if a >= 2 {
            fmt.Println(a - 2)
        }
    }
}
