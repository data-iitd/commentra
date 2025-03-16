package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
func main() {
    var (
        n, m int
        s, t string
        a, b, c, d int
    )
    fmt.Scanf("%d %d", &n, &m)
    s = strings.ToLower(bufio.NewReader(os.Stdin).ReadString('\n'))
    t = strings.ToLower(bufio.NewReader(os.Stdin).ReadString('\n'))
    a, b, c, d = values()
    fmt.Println(s)
    fmt.Println(t)
    fmt.Println(a, b, c, d)
}
func values() (a, b, c, d int) {
    fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)
    return
}
