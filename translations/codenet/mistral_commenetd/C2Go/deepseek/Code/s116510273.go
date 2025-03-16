package main

import (
    "fmt"
    "strings"
)

func main() {
    var mes string
    fmt.Scan(&mes)

    // Logic starts here
    length := len(mes)
    fmt.Printf("%c%d%c\n", mes[0], length-2, mes[length-1])
}

