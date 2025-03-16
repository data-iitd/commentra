<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
)

func main() {
    var r float64
    fmt.Scanf("%lf", &r)
    area := r * r * math.Pi
    circumference := 2 * math.Pi * r
    fmt.Printf("%.10f %.10f\n", area, circumference)
}
