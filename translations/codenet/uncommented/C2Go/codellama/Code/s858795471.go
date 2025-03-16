package main

import "fmt"

func search(A []int, n int, key int) bool {
    A = append(A, key)
    for i := 0; i < n; i++ {
        if A[i] == key {
            return true
        }
    }
    return false
}

func main() {
    var n, q, key, sum int
    var A []int

    fmt.Scan(&n)
    A = make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&A[i])
    }
    fmt.Scan(&q)
    for i := 0; i < q; i++ {
        fmt.Scan(&key)
        if search(A, n, key) {
            sum++
        }
    }
    fmt.Println(sum)
}

