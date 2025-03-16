
package main

import (
    "fmt"
    "os"
    "bufio"
    "strings"
)

func main() {
    var n int
    var str string

    fmt.Print("Enter a string: ")
    fmt.Scanln(&str)

    n = len(str)

    if n%2 == 0 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

