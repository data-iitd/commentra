package main

import (
    "fmt"
    "strings"
)

func main() {
    var n, k int
    fmt.Scan(&n, &k)
    elems := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&elems[i])
    }
    allSame := func(arr []int) bool {
        for i := 1; i < len(arr); i++ {
            if arr[i] != arr[0] {
                return false
            }
        }
        return true
    }
    if allSame(elems) {
        fmt.Println(0)
        return
    }
    if k == 1 {
        fmt.Println(-1)
        return
    }
    if !allSame(elems[k-1:]) {
        fmt.Println(-1)
        return
    }
    target := elems[len(elems)-1]
    toDelete := elems[0 : k-1]
    for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
        toDelete = toDelete[0 : len(toDelete)-1]
    }
    fmt.Println(len(toDelete))
}

// 