
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    reader = bufio.NewReader(os.Stdin)
    writer = bufio.NewWriter(os.Stdout)
)

func main() {
    n, _ := strconv.Atoi(read())
    arr := read_int_array()
    ans := make([]int, n)
    mx := arr[n-1]
    for i := n - 2; i >= 0; i-- {
        ans[i] = max(0, mx-arr[i]+1)
        if arr[i] > mx {
            mx = arr[i]
        }
    }
    for _, v := range ans {
        fmt.Printf("%d ", v)
    }
    fmt.Println()
}

func read() string {
    s, _ := reader.ReadString('\n')
    return strings.TrimSpace(s)
}

func read_int() int {
    s, _ := reader.ReadString('\n')
    x, _ := strconv.Atoi(s)
    return x
}

func read_int_array() []int {
    s, _ := reader.ReadString('\n')
    data := strings.Split(s, " ")
    var a []int
    for _, x := range data {
        x, _ := strconv.Atoi(x)
        a = append(a, x)
    }
    return a
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

