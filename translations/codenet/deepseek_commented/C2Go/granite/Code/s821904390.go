
package main

import "fmt"

func main() {
    var in int
    fmt.Scan(&in)

    h := in / 3600
    in %= 3600
    m := in / 60
    in %= 60
    s := in

    fmt.Printf("%d:%d:%d\n", h, m, s)
}

