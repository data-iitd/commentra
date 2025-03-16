package main

import (
    "fmt"
)

func check(x, y int) string {
    if y%2 == 0 {
        t := (y / 2) - x
        if t >= 0 && (x-t) >= 0 {
            return "Yes"
        }
    }
    return "No"
}

func main() {
    var x, y int
    fmt.Scan(&x, &y)

    fmt.Println(check(x, y))
}

// <END-OF-CODE>
