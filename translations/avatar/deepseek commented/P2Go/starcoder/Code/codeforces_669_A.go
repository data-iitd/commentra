
package main

import "fmt"

func factorial(n int) int {
    if n == 0 {
        return 1
    }
    return n * factorial(n - 1)
}

func fibonacci(n int) int {
    if n <= 0 {
        return 0
    }
    if n == 1 {
        return 1
    }
    a, b := 0, 1
    for i := 2; i <= n; i++ {
        a, b = b, a + b
    }
    return b
}

func main() {
    var n int
    fmt.Scanf("%d", &n)
    fmt.Printf("%d\n", fibonacci(n))
}

