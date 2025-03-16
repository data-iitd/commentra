package main
import "fmt"
import "strings"
func main() {
    var n int
    fmt.Scanf("%d\n", &n)
    for ; n > 0; n-- {
        s := ""
        fmt.Scanf("%s", &s)
        s = strings.Replace(s, "Hoshino", "a", -1)
        fmt.Printf("%s", s)
    }
}
