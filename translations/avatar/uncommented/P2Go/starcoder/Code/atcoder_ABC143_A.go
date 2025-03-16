package main
import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var A, B int
    fmt.Scanf("%d %d", &A, &B)
    ans := A - 2 * B
    if ans < 0 {
        ans = 0
    }
    fmt.Printf("%d\n", ans)
}

