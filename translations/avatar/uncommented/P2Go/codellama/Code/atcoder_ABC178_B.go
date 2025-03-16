package main
import "fmt"
func main() {
    var a, b, c, d int
    fmt.Scan(&a, &b, &c, &d)
    fmt.Println(max(a*c, b*d, a*d, b*c))
}
func max(a, b, c, d int) int {
    if a > b {
        if a > c {
            if a > d {
                return a
            } else {
                return d
            }
        } else {
            if c > d {
                return c
            } else {
                return d
            }
        }
    } else {
        if b > c {
            if b > d {
                return b
            } else {
                return d
            }
        } else {
            if c > d {
                return c
            } else {
                return d
            }
        }
    }
    return a
}
