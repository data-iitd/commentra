package main

import "fmt"

func you(x, y int) int {
    for {
        z := x % y
        x = y
        y = z
        if y <= 0 {
            break
        }
    }
    return x
}

func main() {
    var x, y int
    fmt.Scan(&x, &y)
    var z int
    if x >= y {
        z = you(x, y)
    } else {
        z = you(y, x)
    }
    fmt.Println(z)
}

