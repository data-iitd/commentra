package main
import (
    "fmt"
    "math"
)
func main() {
    var N int
    fmt.Scan( &N )
    XY := make( [][2]int, N )
    for i := range XY {
        fmt.Scan( &XY[i][0], &XY[i][1] )
    }
    for i, xy := range XY {
        D := make( []float64, N )
        for j, x := range XY {
            if i == j {
                continue
            }
            D[j] = math.Atan2( float64( xy[0] - x[0] ), float64( xy[1] - x[1] ) )
        }
        D = append( D, D[0] + 2 * math.Pi )
        ans := 0.0
        for a, b := range D {
            if b - a >= math.Pi {
                ans += b - a - math.Pi
            }
        }
        fmt.Printf( "%.10f\n", ans / ( 2 * math.Pi ) )
}
}
