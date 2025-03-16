package main
import "fmt"
import "strings"
import "strconv"

func main() {
    var a, b, c int
    fmt.Scanf("%d %d %d", &a, &b, &c)
    if a == 5 && b == 5 && c == 5 {
        fmt.Println("YES")
    } else if a == 5 && b == 5 || a == 5 && c == 5 || b == 5 && c == 5 {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

