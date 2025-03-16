
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    var r float64
    var s, l float64
    var p float64 = 3.141592653589

    fmt.Scanf("%f", &r)

    s = math.Pow(r, 2) * p
    l = 2 * p * r

    fmt.Printf("%f %f\n", s, l)
}

