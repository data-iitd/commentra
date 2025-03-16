package main
import "fmt"
func main() {
    var N, d, x int
    fmt.Scan(&N, &d, &x)
    ret := 0
    for N > 0 {
        ret += d + (N - 0.5) * float64(x)
        d += d / float64(N) + (5 * float64(x)) / (2 * float64(N))
        x += 2 * float64(x) / float64(N)
        N--
    }
    fmt.Println(ret)
}



Translate the above Go code to C++ and end with comment "