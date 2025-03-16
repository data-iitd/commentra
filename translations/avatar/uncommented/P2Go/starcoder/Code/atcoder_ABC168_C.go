package main
import (
    "fmt"
    "math"
)
func main() {
    var a, b, h, m int
    fmt.Scanf("%d %d %d %d", &a, &b, &h, &m)
    C := math.Abs(360.0/60.0*float64(m)-360.0/12.0*float64(h)-360.0/12.0/60.0*float64(m))
    if C > 180 {
        C = 360 - C
    }
    cosC := math.Cos(math.Pi*C/180)
    fmt.Printf("%.2f\n", math.Sqrt(float64(a*a+b*b-2*a*b*cosC)))
}
