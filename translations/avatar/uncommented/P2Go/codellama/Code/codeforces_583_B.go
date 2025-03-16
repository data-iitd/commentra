package main

import (
    "fmt"
    "strconv"
    "strings"
)

func main() {
    var n int
    fmt.Scan(&n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
    }
    current_level := 0
    counter := 0
    counter_turns := -1
    for counter < len(a) {
        counter_turns++
        for i := 0; i < len(a); i++ {
            if a[i] != -1 && a[i] <= counter {
                counter++
                a[i] = -1
            }
        }
        a = reverse(a)
    }
    fmt.Println(counter_turns)
}

func reverse(a []int) []int {
    for i := 0; i < len(a)/2; i++ {
        a[i], a[len(a)-i-1] = a[len(a)-i-1], a[i]
    }
    return a
}

