package main
import "fmt"

func main() {
    var n, k, x, y int
    fmt.Scanf("%d %d %d %d", &n, &k, &x, &y)
    sum := 0
    for i := 1; i <= n; i++ {
        if i > k {
            sum += y
        } else {
            sum += x
        }
    }
    fmt.Println(sum)
}

