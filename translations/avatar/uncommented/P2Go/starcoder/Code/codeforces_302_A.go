package main
import (
    "fmt"
    "os"
    "strconv"
    "strings"
)
func main() {
    var n, m int
    fmt.Sscanf(strings.TrimSpace(os.Args[1]), "%d", &n)
    fmt.Sscanf(strings.TrimSpace(os.Args[2]), "%d", &m)
    sa := strings.Count(strings.TrimSpace(os.Args[3]), "-")
    sa = min(n-sa, sa)
    ss := make([]string, m)
    for i := 0; i < m; i++ {
        var a, b int
        fmt.Sscanf(strings.TrimSpace(os.Args[i+4]), "%d %d", &a, &b)
        b -= a
        ss[i] = fmt.Sprintf("%d\n", b%2 == 0 && b <= sa*2)
    }
    fmt.Printf("%s", strings.Join(ss, ""))
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
