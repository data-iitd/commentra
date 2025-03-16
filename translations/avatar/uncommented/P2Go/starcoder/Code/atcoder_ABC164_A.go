package main
import (
    "fmt"
    "os"
    "strconv"
    "strings"
)
func main() {
    var S, W int
    fmt.Sscanf(strings.TrimSpace(os.Args[1]), "%d", &S)
    fmt.Sscanf(strings.TrimSpace(os.Args[2]), "%d", &W)
    if S <= W {
        fmt.Println("safe")
    } else {
        fmt.Println("unsafe")
    }
}
