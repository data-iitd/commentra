
package main

import (
    "fmt"
    "math"
)

func main() {
    var N, A, B int64
    fmt.Scan(&N, &A, &B)

    if !isValidInput(N, A, B) {
        fmt.Println(N)
        return
    }

    k := calculateK(N, A, B)

    if remainingPartGreaterThanA(N, k, A) {
        fmt.Println(a*k + (n - k*(a+b)) - (n - (k*(a+b)+a)))
    } else {
        fmt.Println(a*k + (n - k*(a+b)))
    }
}

func isValidInput(n, a, b int64) bool {
    return 1 <= n && n <= int64(math.Pow(10, 18)) && 0 <= a && 0 <= b && 0 < a+b && a+b <= int64(math.Pow(10, 18))
}

func calculateK(n, a, b int64) int64 {
    return n / (a + b)
}

func remainingPartGreaterThanA(n, k, a int64) bool {
    return (n - k*(a+b)) > a
}

