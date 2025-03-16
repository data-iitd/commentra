package main
import "fmt"
func main() {
    var a, b int
    fmt.Scanf("%d %d", &a, &b)
    fmt.Printf("%d\n", min(a, b))
    fmt.Printf("%d\n", (max(a, b) - min(a, b)) / 2)
}

