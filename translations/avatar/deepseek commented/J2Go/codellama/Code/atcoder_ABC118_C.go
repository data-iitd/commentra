
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n int
    var a []int
    var ans int
    var min int
    var i int
    var j int
    var temp int

    n, _ = strconv.Atoi(os.Args[1])
    a = make([]int, n)
    for i = 0; i < n; i++ {
        a[i], _ = strconv.Atoi(os.Args[i+2])
    }
    if n == 1 {
        fmt.Println(a[0])
        os.Exit(0)
    }
    for i = 0; i < n; i++ {
        if a[i] == 0 {
            a = append(a[:i], a[i+1:]...)
            i--
        }
    }
    if a[len(a)-1] == 0 {
        fmt.Println(0)
        os.Exit(0)
    }
    for {
        if len(a) == 1 {
            ans = a[0]
            break
        }
        a = func(a)
    }
    fmt.Println(ans)
}

func func(a []int) []int {
    var min int
    var i int
    var j int
    var temp int

    min = 0
    for i = 0; i < len(a); i++ {
        if a[i] == 0 {
            a = append(a[:i], a[i+1:]...)
            i--
        } else {
            if min != 0 {
                a[i] = a[i] % min
                if a[i] == 1 {
                    fmt.Println(1)
                    os.Exit(0)
                }
            } else {
                min = a[i]
            }
        }
    }
    for i = 0; i < len(a)-1; i++ {
        for j = i + 1; j < len(a); j++ {
            if a[i] > a[j] {
                temp = a[i]
                a[i] = a[j]
                a[j] = temp
            }
        }
    }
    return a
}

