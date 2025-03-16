
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var a int
    fmt.Scanf("%d", &a)
    if a == 0 {
        fmt.Println(1)
    } else {
        fmt.Println(0)
    }
}

