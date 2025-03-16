
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    n, _ := strconv.Atoi(read())
    l := make([]int, n)
    for i := 0; i < n; i++ {
        l[i], _ = strconv.Atoi(read())
    }
    ans := n - 1
    last := 0
    for _, i := range l {
        ans += abs(last-i) + 1
        last = i
    }
    fmt.Println(ans)
}

func read() string {
    s, _ := in.ReadString('\n')
    return s[:len(s)-1]
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

