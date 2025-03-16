package main
import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scanf("%d\n", &n)
    for ; n > 0; n-- {
        var p, q int
        fmt.Scanf("%d %d\n", &p, &q)
        l := int(math.Sqrt(float64(p*p + q*q)))
        isprime := true
        for i := 0; i < l; i++ {
            for j := 0; j < l; j++ {
                x := i*i + j*j
                if x <= 1 || x >= p*p + q*q {
                    continue
                }
                if (i*p + j*q) % x == 0 && (i*q - j*p) % x == 0 {
                    isprime = false
                    break
                }
            }
            if!isprime {
                break
            }
        }
        fmt.Printf("%s\n", "P" if isprime else "C")
    }
}

