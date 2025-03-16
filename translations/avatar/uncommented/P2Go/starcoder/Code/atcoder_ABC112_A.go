package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    age, _ := strconv.Atoi(os.Args[1])
    if age == 1 {
        fmt.Println("Hello World")
    } else {
        a, b := 0, 0
        fmt.Sscanf(os.Args[2], "%d", &a)
        fmt.Sscanf(os.Args[3], "%d", &b)
        fmt.Println(a + b)
    }
}

