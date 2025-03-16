package main

import "fmt"

func search(A []int, n int, key int) int {
    i := 0
    A = append(A, key)
    for A[i] != key {
        i++
    }
    if i != n {
        return 1
    }
    return 0
}

func main() {
    var n, q, key, sum int
    var A []int
    var i int

    fmt.Scan(&n)
    A = make([]int, n)
    for i = 0; i < n; i++ {
        fmt.Scan(&A[i])
    }
    fmt.Scan(&q)
    for i = 0; i < q; i++ {
        fmt.Scan(&key)
        if search(A, n, key) == 1 {
            sum++
        }
    }
    fmt.Println(sum)
}

