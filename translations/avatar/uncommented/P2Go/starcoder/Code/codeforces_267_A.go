package main
import "fmt"
func substract ( a, b int ) int {
    if a > b {
        total := 0
        for a > 0 && b > 0 {
            total += a / b
            a = a % b
            if a > 0 {
                total += b / a
                b = b % a
        }
        return total
    }
    if a < b {
        total := 0
        for a > 0 && b > 0 {
            total += b / a
            b = b % a
            if b > 0 {
                total += a / b
                a = a % b
        }
        return total
    }
    if a == b {
        return 1
    }
}
func main() {
    var n int
    fmt.Scanf("%d", &n)
    var lst []int
    for i := 0; i < n; i++ {
        var a, b int
        fmt.Scanf("%d %d", &a, &b)
        lst = append(lst, substract(a, b))
    }
    for _, i := range lst {
        fmt.Println(i)
    }
}
