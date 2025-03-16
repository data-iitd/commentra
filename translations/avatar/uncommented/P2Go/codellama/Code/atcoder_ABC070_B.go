
package main

import "fmt"

func main() {
    var A []int
    fmt.Scan(&A)
    if A[1] <= A[2] || A[3] <= A[0] {
        fmt.Println(0)
    } else {
        A = append(A, A[2], A[1])
        sort.Ints(A)
        fmt.Println(A[2] - A[1])
    }
}

