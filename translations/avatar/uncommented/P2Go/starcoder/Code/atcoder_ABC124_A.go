package main
import "fmt"
func main() {
    var a, b int
    fmt.Scanf("%d %d", &a, &b)
    c := 0
    for i := 0; i < 2; i++ {
        c += max(a, b)
        if a >= b {
            a -= 1
        } else {
            b -= 1
        }
    }
    fmt.Println(c)
}

