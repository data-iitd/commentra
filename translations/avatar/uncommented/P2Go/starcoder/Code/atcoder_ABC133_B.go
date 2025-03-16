package main
import (
    "fmt"
    "math"
)
func dist(x, y []float64) float64 {
    tmp := 0.0
    for i := 0; i < len(x); i++ {
        tmp += (x[i] - y[i]) * (x[i] - y[i])
    }
    return math.Sqrt(tmp)
}
func main() {
    var n, d int
    fmt.Scanf("%d %d", &n, &d)
    points := make([][]float64, n)
    for i := 0; i < n; i++ {
        points[i] = make([]float64, d)
        for j := 0; j < d; j++ {
            fmt.Scanf("%f", &points[i][j])
        }
    }
    count := 0
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            if math.Floor(dist(points[i], points[j])) == 0 {
                count++
            }
        }
    }
    fmt.Println(count)
}
