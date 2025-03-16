package main
import (
    "fmt"
    "strings"
)
func main() {
    var n int
    fmt.Scanf("%d", &n)
    m := strings.Split(strings.TrimSpace(readLine()), " ")
    possible := true
    for _, i := range(set(m)) {
        if strings.Count(strings.Join(m, ""), i) >= n/2+1 {
            possible = false
            break
        }
    }
    fmt.Println("YES" if possible else "NO")
}
