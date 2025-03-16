
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n, k, z int
    var err error
    fmt.Print("Enter n: ")
    n, err = strconv.Atoi(os.Args[1])
    if err != nil {
        fmt.Println("Error:", err)
        return
    }
    fmt.Print("Enter k: ")
    k, err = strconv.Atoi(os.Args[2])
    if err != nil {
        fmt.Println("Error:", err)
        return
    }
    n++
    if n%k != 0 {
        z = k - n%k
    }
    fmt.Println(n + z)
}

