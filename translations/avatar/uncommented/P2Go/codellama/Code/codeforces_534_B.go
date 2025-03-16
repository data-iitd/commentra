
package main

import "fmt"

func main() {
    var v1, v2, t, d int
    fmt.Scan(&v1, &v2, &t, &d)
    var a int = 1
    var v int = v1
    var distance int = 0
    for i := 0; i < t; i++ {
        if v-v2 > (t-i-1)*d {
            a *= -1
            v = (t-i-1)*d + v2
        }
        distance += v
        v += a * d
    }
    fmt.Println(distance)
}

