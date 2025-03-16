
package main

import (
    "fmt"
    "os"
)

func main() {
    in := 0
    fmt.Fscanf(os.Stdin, "%d", &in)

    h := in / 3600
    in %= 3600

    m := in / 60
    in %= 60

    s := in

    fmt.Printf("%d:%d:%d\n", h, m, s)
}

