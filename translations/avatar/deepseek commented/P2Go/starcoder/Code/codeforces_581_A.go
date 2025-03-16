
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    n, _ := strconv.Atoi(os.Args[1])
    factorial := 1
    for i := 1; i <= n; i++ {
        factorial *= i
    }
    fmt.Println(factorial)
}

