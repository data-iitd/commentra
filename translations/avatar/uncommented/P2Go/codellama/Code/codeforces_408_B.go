package main
import "fmt"
import "sort"
func main() {
    var t int
    fmt.Scan(&t)
    for i := 0; i < t; i++ {
        var line string
        fmt.Scan(&line)
        bought_count := make(map[string]int)
        for _, v := range line {
            bought_count[string(v)]++
        }
        fmt.Scan(&line)
        made_cout := make(map[string]int)
        for _, v := range line {
            made_cout[string(v)]++
        }
        res := 0
        for k, v := range made_cout {
            if _, ok := bought_count[k]; !ok {
                fmt.Println(-1)
                return
            }
            res += min(bought_count[k], v)
        }
        fmt.Println(res)
    }
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
