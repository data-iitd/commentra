package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function declarations
func A() {
}

func B() {
    var x int64
    var sum int64
    var i int
    var str string
    fmt.Scanln(&str)
    x, _ = strconv.ParseInt(str, 10, 64)
    sum = 100
    for i = 0; sum < x; i++ {
        sum += sum / 100
    }
    fmt.Println(i)
}

func C() {
}

func D() {
}

func main() {
    B()
}

