package main

import "fmt"

func main() {
    var str [30]byte
    fmt.Scanf("%s", &str)
    str[5] =''
    str[13] =''
    fmt.Printf("%s\n", str)
}

