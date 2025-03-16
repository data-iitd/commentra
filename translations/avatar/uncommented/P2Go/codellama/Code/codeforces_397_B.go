package main
import "fmt"
func main() {
    var t int
    fmt.Scan(&t)
    for i := 0; i < t; i++ {
        var a, b, c int
        fmt.Scan(&a, &b, &c)
        if a%b == 0 {
            fmt.Println("Yes")
        } else {
            fmt.Println("No")
        }
    }
}
