package main

import (
    "fmt"
    "math"
)

// gcd computes the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
    // Ensure 'a' is the larger number for the algorithm
    if a < b {
        a, b = b, a
    }
    r := a % b
    for r > 0 {
        a = b
        b = r
        r = a % b
    }
    return b
}

func main() {
    var n int
    fmt.Scanf("%d", &n)
    ans := 0
    fmt.Scanf("%d", &ans)
    for i := 1; i < n; i++ {
        var a int
        fmt.Scanf("%d", &a)
        ans = gcd(ans, a)
    }
    fmt.Println(ans)
}

