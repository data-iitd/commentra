
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var k int
    fmt.Fscanf(reader, "%d\n", &k)
    a := make([]int, k)
    for i := 0; i < k; i++ {
        fmt.Fscanf(reader, "%d\n", &a[i])
    }
    max := 3
    min := 2
    if a[k-1]!= 2 {
        fmt.Println(-1)
        return
    }
    for i := k - 2; i >= 0; i-- {
        if a[i] > max {
            fmt.Println(-1)
            return
        }
        max = ((max / a[i]) + 1) * a[i] - 1
        if min%a[i]!= 0 {
            min = ((min / a[i]) + 1) * a[i]
        }
        if max <= min {
            fmt.Println(-1)
            return
        }
    }
    fmt.Printf("%d %d\n", min, max)
}

