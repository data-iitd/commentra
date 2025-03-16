package main
import "fmt"
func main() {
    n := 0
    t := 0
    for i := 0; i < n; i++ {
        if i+1&1 == 1 {
            t += 1
        }
    }
    fmt.Printf("%.6f\n", float64(t)/float64(n))
}
