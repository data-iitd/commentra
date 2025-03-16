
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    N = 368
    m = make([]int, N)
    f = make([]int, N)
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialCapacity = 4096
    const eof = -1
    scanner.Buffer(make([]byte, initialCapacity), initialCapacity)
    scanner.Split(bufio.ScanWords)
    var n int
    scanner.Scan()
    n, _ = fmt.Sscanf(scanner.Text(), "%d")
    for i := 0; i < n; i++ {
        scanner.Scan()
        x := scanner.Text()
        var a, b int
        scanner.Scan()
        a, _ = fmt.Sscanf(scanner.Text(), "%d")
        scanner.Scan()
        b, _ = fmt.Sscanf(scanner.Text(), "%d")
        b++
        if x == "M" {
            m[a] += 2
            m[b] -= 2
        } else {
            f[a] += 2
            f[b] -= 2
        }
    }
    a, b, c := 0, 0, 0
    for i := 0; i < N; i++ {
        a += m[i]
        b += f[i]
        if min(a, b) > c {
            c = min(a, b)
        }
    }
    fmt.Println(c)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

