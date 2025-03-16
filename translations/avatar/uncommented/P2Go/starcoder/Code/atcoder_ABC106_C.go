package main
import "fmt"
func main() {
    s := S()
    k := I()
    l := 0
    for _, c := range s {
        if c!= '1' {
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
func S() string {
    var s string
    fmt.Scan(&s)
    return s
}
func I() int {
    var i int
    fmt.Scan(&i)
    return i
}
