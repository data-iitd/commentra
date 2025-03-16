package main
import "fmt"
func main() {
    var s string
    fmt.Scan(&s)
    var k int
    fmt.Scan(&k)
    l := 0
    for _, c := range s {
        if c != '1' {
            break
        }
        l++
    }
    if l >= k {
        fmt.Println(1)
    } else {
        fmt.Println(s[l])
    }
}
