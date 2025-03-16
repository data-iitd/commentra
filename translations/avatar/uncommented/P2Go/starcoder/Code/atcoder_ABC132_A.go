package main
import (
    "fmt"
    "strings"
)
func main() {
    var S string
    fmt.Scanf("%s", &S)
    c := make(map[rune]int)
    for _, v := range S {
        c[v]++
    }
    if len(c)!= 2 {
        fmt.Println("No")
        return
    }
    for _, v := range c {
        if v!= 2 {
            fmt.Println("No")
            return
        }
    }
    fmt.Println("Yes")
}
