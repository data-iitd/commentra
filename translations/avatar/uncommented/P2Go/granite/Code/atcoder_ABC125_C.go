
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

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
    for i := n - 1; i >= 0; i-- {
        right[i] = op(right[i+1], array[i])
    }
    return left, right
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialBufSize = 4096
    const maxBufSize = 1000000
    scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
    scanner.Split(bufio.ScanWords)
    var n int
    scanner.Scan()
    n, _ = strconv.Atoi(scanner.Text())
    a := make([]int, n)
    for i := 0; i < n; i++ {
        scanner.Scan()
        a[i], _ = strconv.Atoi(scanner.Text())
    }
    left, right := ruiseki_lr(a)
    ans := 0
    for i := 0; i < n; i++ {
        ans = max(gcd(left[i], right[i+1]), ans)
    }
    fmt.Println(ans)
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

