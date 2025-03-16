
package main

import "fmt"

func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a%b)
}

func ruiseki_lr(array []int) ([]int, []int) {
    op := func(a, b int) int {
        return gcd(a, b)
    }
    e := 0
    n := len(array)
    left := make([]int, n+1)
    right := make([]int, n+1)
    for i := 0; i < n; i++ {
        left[i+1] = op(left[i], array[i])
    }
    for i := n-1; i >= 0; i-- {
        right[i] = op(right[i+1], array[i])
    }
    return left, right
}

func main() {
    var n int
    fmt.Scanf("%d\n", &n)
    array := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d\n", &array[i])
    }
    left, right := ruiseki_lr(array)
    ans := 0
    for i := 0; i < n; i++ {
        ans = max(gcd(left[i], right[i+1]), ans)
    }
    fmt.Printf("%d\n", ans)
}

// 