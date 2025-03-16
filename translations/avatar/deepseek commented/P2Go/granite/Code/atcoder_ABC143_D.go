

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialBufSize = 4096
    const maxBufSize = 1000000
    scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
    scanner.Split(bufio.ScanWords)
    var n int
    scanner.Scan()
    n, _ = fmt.Sscanf(scanner.Text(), "%d")
    l := make([]int, n)
    for i := 0; i < n; i++ {
        scanner.Scan()
        fmt.Sscanf(scanner.Text(), "%d", &l[i])
    }
    sort.Ints(l)
    ans := 0
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            a, b := l[i], l[j]
            right := sort.Search(n, func(x int) bool {
                return l[x] >= a+b
            })
            left := sort.Search(n, func(x int) bool {
                return l[x] >= max(a-b, b-a)
            })
            tmp := right - left
            if left <= i && i < right {
                tmp--
            }
            if left <= j && j < right {
                tmp--
            }
            ans += tmp
        }
    }
    fmt.Println(ans / 3)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

