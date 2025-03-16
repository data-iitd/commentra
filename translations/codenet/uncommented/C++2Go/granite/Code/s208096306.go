
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func gcd(a, b int) int {
    if a < b {
        a, b = b, a
    }
    r := a % b
    for r > 0 {
        a, b = b, r
        r = a % b
    }
    return b
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

    var ans int
    scanner.Scan()
    ans, _ = strconv.Atoi(scanner.Text())

    for i := 1; i < n; i++ {
        scanner.Scan()
        a, _ := strconv.Atoi(scanner.Text())
        ans = gcd(ans, a)
    }

    fmt.Println(ans)
}

