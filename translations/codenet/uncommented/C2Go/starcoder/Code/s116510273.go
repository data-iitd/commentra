package main

import (
    "fmt"
    "strings"
)

func main() {
    var mes string
    fmt.Scanf("%s", &mes)
    fmt.Printf("%c%v%c\n", mes[0], len(mes)-2, mes[len(mes)-1])
}

